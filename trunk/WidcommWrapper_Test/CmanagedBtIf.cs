using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using CG.Wrappers.Widcomm.Datatypes;
using CG.Wrappers.Widcomm.Enums;

namespace CG.Wrappers.Widcomm.Tests
{
	public partial class CManagedBtIf_Form : Form
	{
		public CManagedBtIf_Form()
		{
			InitializeComponent();

			Trace.Listeners.Add(new Logger(textBox1));
		}

		private CManagedBtIf _cManagedBtIfInstance;
		public CManagedBtIf CManagedBtIfInstance
		{
			get
			{
				if (!CManagedBtIf.IsDllPresent())
					throw new FileNotFoundException("Unable to load btwapi.dll");

				if (_cManagedBtIfInstance == null)
					_cManagedBtIfInstance = new CManagedBtIf();

				return _cManagedBtIfInstance;
			}
		}

		private DeviceAddress GetAddress(string t)
		{
			try
			{
				return DeviceAddress.ConvertFrom(t);
			}
			catch (Exception ex)
			{
				Trace.TraceError("Unable to convert address: {0}", ex.Message);
				return null;
			}
		}

		#region GroupBox1

		private void btn1_IsBtwapiFound_Click(object sender, EventArgs e)
		{
			Trace.TraceInformation("IsDllPresent() returns: {0}", CManagedBtIf.IsDllPresent());
		}

		private void btn1_IsStackServerUp_Click(object sender, EventArgs e)
		{
			Trace.TraceInformation("IsStackServerUp() returns: {0}", CManagedBtIfInstance.IsStackServerUp());
		}

		private void btn1_IsDeviceReady_Click(object sender, EventArgs e)
		{
			Trace.TraceInformation("IsDeviceReady() returns: {0}", CManagedBtIfInstance.IsDeviceReady());
		}

		private void chk1_TrackStackStatusChange_CheckedChanged(object sender, EventArgs e)
		{
			if (chk1_TrackStackStatusChange.Checked)
			{
				Trace.TraceInformation("Start stack status changes tracking");
				CManagedBtIfInstance.StackStatusChange += new CManagedBtIf.StackStatusChangeDelegate(CManagerBtIfInstance_StackStatusChange);
			}
			else
			{
				Trace.TraceInformation("Stop stack status changes tracking");
				CManagedBtIfInstance.StackStatusChange -= new CManagedBtIf.StackStatusChangeDelegate(CManagerBtIfInstance_StackStatusChange);
			}
		}

		void CManagerBtIfInstance_StackStatusChange(CG.Wrappers.Widcomm.Enums.eStackStatus newStatus)
		{
			Trace.TraceInformation("Stack status changed. New status: {0}", newStatus);
		}

		#endregion

		#region GroupBox2

		private void btn2_StartInquiry_Click(object sender, EventArgs e)
		{
			btn2_StartInquiry.Enabled = false;
			btn2_StopInquiry.Enabled = true;

			Trace.TraceInformation("Start inquiry");

			CManagedBtIfInstance.DeviceResponded += new CManagedBtIf.DeviceRespondedDelegate(CManagedBtIfInstance_DeviceResponded);
			CManagedBtIfInstance.InquiryComplete += new CManagedBtIf.InquiryCompleteDelegate(CManagedBtIfInstance_InquiryComplete);
			bool ret = CManagedBtIfInstance.StartInquiry();
			if (false == ret)
			{
				CManagedBtIfInstance.DeviceResponded -= new CManagedBtIf.DeviceRespondedDelegate(CManagedBtIfInstance_DeviceResponded);
				CManagedBtIfInstance.InquiryComplete -= new CManagedBtIf.InquiryCompleteDelegate(CManagedBtIfInstance_InquiryComplete);
				btn2_StartInquiry.Enabled = true;
				btn2_StopInquiry.Enabled = false;
			}

			Trace.TraceInformation("Start inquiry status: {0}", ret);
		}

		void CManagedBtIfInstance_InquiryComplete(bool success, short numResponses)
		{
			CManagedBtIfInstance.DeviceResponded -= new CManagedBtIf.DeviceRespondedDelegate(CManagedBtIfInstance_DeviceResponded);
			CManagedBtIfInstance.InquiryComplete -= new CManagedBtIf.InquiryCompleteDelegate(CManagedBtIfInstance_InquiryComplete);

			Trace.TraceInformation("InquiryComplete status: {0}", success);
			Trace.TraceInformation("Number of devices responding: {0}", numResponses);

			this.Invoke((MethodInvoker) (() =>
			                             	{
			                             		btn2_StartInquiry.Enabled = true;
			                             		btn2_StopInquiry.Enabled = false;
			                             	}));
		}

		void CManagedBtIfInstance_DeviceResponded(CG.Wrappers.Widcomm.Datatypes.DeviceAddress deviceAddress, CG.Wrappers.Widcomm.Datatypes.DeviceClass deviceClass, string deviceName, bool connected)
		{

			Trace.TraceInformation("Device name: {0}, Device addr: {1}, Connected: {2}",
			                       deviceName, deviceAddress, connected);
			Trace.TraceInformation(deviceClass.ToString());
			Trace.Write(Environment.NewLine);
		}

		private void btn2_StopInquiry_Click(object sender, EventArgs e)
		{
			CManagedBtIfInstance.DeviceResponded -= new CManagedBtIf.DeviceRespondedDelegate(CManagedBtIfInstance_DeviceResponded);
			CManagedBtIfInstance.InquiryComplete -= new CManagedBtIf.InquiryCompleteDelegate(CManagedBtIfInstance_InquiryComplete);

			Trace.TraceInformation("Inquiry stopped");
			CManagedBtIfInstance.StopInquiry();

			btn2_StartInquiry.Enabled = true;
			btn2_StopInquiry.Enabled = false;
		}

		private void btn2_ShowInquiryWindow_Click(object sender, EventArgs e)
		{
			InquiryWindow frm = new InquiryWindow();
			DialogResult dialogResult = frm.ShowDialog();

			Trace.TraceInformation("InquiryWindow closed, status: {0}", dialogResult);
			if (DialogResult.OK == dialogResult)
			{
				if (null == frm.SelectedItem)
				{
					Trace.TraceInformation("None device selected");
				}
				else
				{
					Trace.TraceInformation("Device selected. Name: {0}, Adress: {1}, Connected: {2}",
					                       frm.SelectedItem.BdName, frm.SelectedItem.DevAddress, frm.SelectedItem.BConnected);
					Trace.TraceInformation(frm.SelectedItem.DevClass.ToString());
				}
			}
		}

		#endregion

		#region GroupBox3

		private void btn3_StartDiscoverySimple_Click(object sender, EventArgs e)
		{
			StartDiscovery(false);
		}

		private void btn3_StartDiscoveryAdvanced_Click(object sender, EventArgs e)
		{
			StartDiscovery(true);
		}

		private void StartDiscovery(bool advanced)
		{
			Trace.TraceInformation("Start discovery");
			if (advanced)
			{
				CManagedBtIfInstance.DiscoveryCompleteWithInfos += new CManagedBtIf.DiscoveryCompleteWithInfosDelegate(CManagedBtIfInstance_DiscoveryCompleteWithInfos);
			}
			else
			{
				CManagedBtIfInstance.DiscoveryComplete += new CManagedBtIf.DiscoveryCompleteDelegate(CManagedBtIfInstance_DiscoveryComplete);
			}


			if (GetAddress(msk3_Address.Text) == null)
				return;

			btn3_StartDiscoverySimple.Enabled = false;
			msk3_Address.Enabled = false;

			bool ret = CManagedBtIfInstance.StartDiscovery(GetAddress(msk3_Address.Text), eGuidServiceClass.Undefined);
			Trace.TraceInformation("Start discovery status: {0}", ret);
		}

		void CManagedBtIfInstance_DiscoveryCompleteWithInfos(short numRecs, CG.Wrappers.Widcomm.Enums.WBT_STATUS_CODE resultCode)
		{
			CManagedBtIfInstance.DiscoveryCompleteWithInfos -= new CManagedBtIf.DiscoveryCompleteWithInfosDelegate(CManagedBtIfInstance_DiscoveryCompleteWithInfos);

			Trace.TraceInformation("Discovery with infos complete");
			Trace.TraceInformation("Found services: {0}, Result code: {1}", numRecs, resultCode);

			CG.Wrappers.Widcomm.CManagedSdpDiscoveryRec[] recs = null;
			int res = CManagedBtIfInstance.ReadDiscoveryRecords(GetAddress(msk3_Address.Text), numRecs, out recs, eGuidServiceClass.Undefined);
			if (res != 0)
			{
				foreach (CManagedSdpDiscoveryRec rec in recs)
				{
					Trace.TraceInformation("Record: {0} ({1}, {2})", rec.ServiceName, rec.ServiceClassEnum, rec.ServiceClassGuid);

					foreach (string attr in Enum.GetNames(typeof(eAttributeId)))
					{
						object[] tabObjects = null;
						bool ret = rec.FindAttribute((eAttributeId)Enum.Parse(typeof(eAttributeId), attr, false), out tabObjects);
						if (ret)
						{
							Trace.TraceInformation("\tEnum: {0} - Result: {1}", attr, ret);

							string s = string.Empty;
							if (ret)
							{
								int i = 0;
								foreach (object o in tabObjects)
								{
									Trace.TraceInformation("\t\t{0}: {1} - {2}", i, o.GetType().Name, o);
									i++;
								}
							}
						}
					}

					rec.Dispose();
				}
			}


			this.Invoke((MethodInvoker)(() =>
			                            	{
			                            		btn3_StartDiscoverySimple.Enabled = true;
			                            		msk3_Address.Enabled = true;
			                            	}));
		}

		void CManagedBtIfInstance_DiscoveryComplete()
		{
			CManagedBtIfInstance.DiscoveryComplete -= new CManagedBtIf.DiscoveryCompleteDelegate(CManagedBtIfInstance_DiscoveryComplete);
			Trace.TraceInformation("Discovery complete");

			ushort discoveryFoundNumber;
			Enums.eDiscoveryResult res = CManagedBtIfInstance.GetLastDiscoveryResult(GetAddress(msk3_Address.Text), out discoveryFoundNumber);
			Trace.TraceInformation("Found services: {0}, Result code: {1}", discoveryFoundNumber, res);


			this.Invoke((MethodInvoker) (() =>
			                             	{
			                             		btn3_StartDiscoverySimple.Enabled = true;
			                             		msk3_Address.Enabled = true;
			                             	}));
		}

		private void btnGetResultsCount_Click(object sender, EventArgs e)
		{
			if (GetAddress(msk3_Address.Text) == null)
				return;

			ushort val;
			Enums.eDiscoveryResult ret = CManagedBtIfInstance.GetLastDiscoveryResult(GetAddress(msk3_Address.Text), out val);
			Trace.TraceInformation("Count results. Result code: {0}, Number: {1}", ret, val);
		}

		#endregion

		#region GroupBox4

		private void btn4_BoundQuery_Click(object sender, EventArgs e)
		{
			if (GetAddress(msk4_Address.Text) == null)
				return;

			bool ret = CManagedBtIfInstance.BondQuery(GetAddress(msk4_Address.Text));
			Trace.TraceInformation("Bound query result: {0}", ret);
		}

		private void btn4_Bound_Click(object sender, EventArgs e)
		{
			if (GetAddress(msk4_Address.Text) == null)
				return;

			Enums.eBondReturnCode ret = CManagedBtIfInstance.Bond(GetAddress(msk4_Address.Text), msk4_Pin.Text);
			Trace.TraceInformation("Bound procedure result: {0}", ret);
		}

		private void btn4_UnBound_Click(object sender, EventArgs e)
		{
			if (GetAddress(msk4_Address.Text) == null)
				return;

			bool ret = CManagedBtIfInstance.UnBond(GetAddress(msk4_Address.Text));
			Trace.TraceInformation("Unbound procedure result: {0}", ret);
		}

		#endregion

		#region GroupBox5

		private void btn5_GetExtendedError_Click(object sender, EventArgs e)
		{
			Trace.TraceInformation("Extended error: {0}", CManagedBtIfInstance.GetExtendedError());
		}

		private void btn5_GetLocalDeviceName_Click(object sender, EventArgs e)
		{
			string name;
			bool ret = CManagedBtIfInstance.GetLocalDeviceName(out name);

			Trace.TraceInformation("Get local device name. Status: {0}, Name: {1}", ret, name);
		}

		private void btn5_GetSDKVersion_Click(object sender, EventArgs e)
		{
			string s;
			bool ret = CManagedBtIfInstance.GetDKVersionInfo(out s);
			if (ret)
			{
				Trace.TraceInformation("DK version info: {0}", s);
			}
			else
			{
				Trace.TraceError("Unable to retrieve DK version info");
			}
		}

		private void btn5_GetBTWVersion_Click(object sender, EventArgs e)
		{
			string s;
			bool ret = CManagedBtIfInstance.GetBTWVersionInfo(out s);
			if (ret)
			{
				Trace.TraceInformation("BTW version info: {0}", s);
			}
			else
			{
				Trace.TraceError("Unable to retrieve BTW version info");
			}
		}

		private void btn5_GetServicesNames_Click(object sender, EventArgs e)
		{
			string s;
			bool ret = CManagedBtIfInstance.GetLocalServiceName(out s);
			if (ret)
			{
				Trace.TraceInformation("Local service name: {0}", s);
				do
				{
					ret = CManagedBtIfInstance.GetNextLocalServiceName(out s);
					if (ret)
					{
						Trace.TraceInformation("Local service name: {0}", s);
					}
				} while (ret);
			}
			else
			{
				Trace.TraceError("Unable to retrieve local services name");
			}
		}

		#endregion

	}



	class Logger : TraceListener
	{
		private TextBox _t;

		public Logger(TextBox t)
		{
			_t = t;
		}


		public override void Write(string message)
		{
			_t.Invoke((MethodInvoker) (() => _t.AppendText(message)));
		}

		public override void WriteLine(string message)
		{
			_t.Invoke((MethodInvoker) (() => _t.AppendText(message + Environment.NewLine)));
		}
	}
}
