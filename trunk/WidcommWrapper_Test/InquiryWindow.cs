using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using CG.Wrappers.Widcomm;
using CG.Wrappers.Widcomm.Datatypes;

namespace CG.Wrappers.Widcomm.Tests
{
	public partial class InquiryWindow : Form
	{
		public InquiryWindow()
		{
			InitializeComponent();
		}

		CG.Wrappers.Widcomm.CManagedBtIf wdStack = new CG.Wrappers.Widcomm.CManagedBtIf();


		#region Properties

		bool isSearching = false;
		bool IsSearching
		{
			get { return isSearching; }
			set
			{
				if (isSearching == value)
					return;

				isSearching = value;
				if (isSearching)
				{
					btnStartStop.Text = "Stop search";
					progressBar1.Visible = true;
				}
				else
				{
					btnStartStop.Text = "Start search";
					progressBar1.Value = 0;
					progressBar1.Visible = false;
				}
			}
		}

		public DeviceItem SelectedItem
		{
			get
			{
				if (listView1.SelectedItems.Count == 0)
				{
					return null;
				}
				else
				{
					return ((DeviceListViewItem)listView1.SelectedItems[0]).DeviceItem;
				}
			}
		}

		#endregion


		#region Buttons

		private void btnStartStop_Click(object sender, EventArgs e)
		{
			if (IsSearching)
			{
				StopSearch();
			}
			else
			{
				StartSearch();
			}
		}

		private void btnCredits_Click(object sender, EventArgs e)
		{
			MessageBox.Show(string.Format("Bluetooth icon from http://www.artistsvalley.com{0}Device icons from http://commons.wikimedia.org/wiki/GNOME_Desktop_icons", Environment.NewLine), this.Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
		}

		private void btnSelect_Click(object sender, EventArgs e)
		{
			DialogResult = DialogResult.OK;
			this.Close();
		}

		#endregion




		private void InquiryWindow_Load(object sender, EventArgs e)
		{
			StartSearch();
		}


		private void InquiryWindow_FormClosing(object sender, FormClosingEventArgs e)
		{
			StopSearch();

			wdStack.Dispose();
		}


		void StartSearch()
		{
			IsSearching = true;

			listView1.Items.Clear();

			wdStack.DeviceResponded += new CG.Wrappers.Widcomm.CManagedBtIf.DeviceRespondedDelegate(wdStack_DeviceResponded);
			wdStack.InquiryComplete += new CG.Wrappers.Widcomm.CManagedBtIf.InquiryCompleteDelegate(wdStack_InquiryComplete);
			if (!wdStack.StartInquiry())
			{
				
			}
		}


		void StopSearch()
		{
			wdStack.DeviceResponded -= new CG.Wrappers.Widcomm.CManagedBtIf.DeviceRespondedDelegate(wdStack_DeviceResponded);
			wdStack.InquiryComplete -= new CG.Wrappers.Widcomm.CManagedBtIf.InquiryCompleteDelegate(wdStack_InquiryComplete);
			IsSearching = false;
		}


		void wdStack_InquiryComplete(bool success, short num_responses)
		{
			this.BeginInvoke((MethodInvoker)(() => StopSearch()));
		}


		void wdStack_DeviceResponded(DeviceAddress bda, DeviceClass devClass, string bdName, bool bConnected)
		{
			this.BeginInvoke((MethodInvoker)delegate
			{
				bool needToCreate = true;
				foreach (DeviceListViewItem item in listView1.Items)
				{
					if (item.DeviceItem.DevAddress.Equals(bda))
					{
						if (string.IsNullOrEmpty(item.DeviceItem.BdName))
						{
							//Replace item if old item has empty name
							listView1.Items.Remove(item);
							needToCreate = true;
						}
						else
						{
							needToCreate = false;

						}
						break;
					}
				}

				if (needToCreate)
				{
					listView1.Items.Add(new DeviceListViewItem(bda, devClass, bdName, bConnected));

				}
			});
		}

		
		private void listView1_DrawItem(object sender, DrawListViewItemEventArgs e)
		{
			e.DrawDefault = true;

			//Draw a checkbox if device is connected
			System.Windows.Forms.VisualStyles.CheckBoxState chkState = (e.Item.Checked == true) ? System.Windows.Forms.VisualStyles.CheckBoxState.CheckedNormal : System.Windows.Forms.VisualStyles.CheckBoxState.UncheckedNormal;
			Size chkSize = System.Windows.Forms.CheckBoxRenderer.GetGlyphSize(e.Graphics, chkState);
			System.Windows.Forms.CheckBoxRenderer.DrawCheckBox(e.Graphics, new Point(e.Bounds.X + 10, ((ListView)sender).LargeImageList.ImageSize.Height - chkSize.Height), chkState);
		}

		private void listView1_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (SelectedItem == null)
			{
				btnSelect.Enabled = false;
			}
			else
			{
				btnSelect.Enabled = true;
			}
		}
	}



	public class DeviceItem
	{
		private DeviceAddress devAddress;
		private DeviceClass devClass;
		private string bdName;
		private bool bConnected;

		public DeviceAddress DevAddress
		{
			get { return devAddress; }
			set { devAddress = value; }
		}

		public DeviceClass DevClass
		{
			get { return devClass; }
			set { devClass = value; }
		}

		public string BdName
		{
			get { return bdName; }
			set { bdName = value; }
		}

		public bool BConnected
		{
			get { return bConnected; }
			set { bConnected = value; }
		}
	}


	class DeviceListViewItem : ListViewItem
	{
		DeviceItem deviceItem;

		internal DeviceItem DeviceItem
		{
			get { return deviceItem; }
		}


		public DeviceListViewItem(DeviceAddress devAddress, DeviceClass devClass, string bdName, bool bConnected)
		{
			deviceItem = new DeviceItem();

			deviceItem.DevAddress = devAddress;
			deviceItem.DevClass = devClass;
			deviceItem.BdName = bdName;
			deviceItem.BConnected = bConnected;

			this.Text = deviceItem.BdName;
			this.ImageKey = deviceItem.DevClass.MajorDeviceClass.ToString();
			this.Checked = deviceItem.BConnected;
		}
	}
}
