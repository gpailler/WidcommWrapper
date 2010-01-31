namespace CG.Wrappers.Widcomm.Tests
{
	partial class InquiryWindow
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}

			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(InquiryWindow));
			this.pnlTop = new System.Windows.Forms.Panel();
			this.lblTopText = new System.Windows.Forms.Label();
			this.lblTitle = new System.Windows.Forms.Label();
			this.pictIcon = new System.Windows.Forms.PictureBox();
			this.btnStartStop = new System.Windows.Forms.Button();
			this.progressBar1 = new System.Windows.Forms.ProgressBar();
			this.listView1 = new System.Windows.Forms.ListView();
			this.imageList1 = new System.Windows.Forms.ImageList(this.components);
			this.btnCredits = new System.Windows.Forms.Button();
			this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
			this.btnSelect = new System.Windows.Forms.Button();
			this.pnlTop.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictIcon)).BeginInit();
			this.SuspendLayout();
			// 
			// pnlTop
			// 
			this.pnlTop.BackColor = System.Drawing.SystemColors.Window;
			this.pnlTop.Controls.Add(this.lblTopText);
			this.pnlTop.Controls.Add(this.lblTitle);
			this.pnlTop.Controls.Add(this.pictIcon);
			this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
			this.pnlTop.Location = new System.Drawing.Point(0, 0);
			this.pnlTop.Name = "pnlTop";
			this.pnlTop.Size = new System.Drawing.Size(495, 67);
			this.pnlTop.TabIndex = 0;
			// 
			// lblTopText
			// 
			this.lblTopText.Location = new System.Drawing.Point(31, 22);
			this.lblTopText.Name = "lblTopText";
			this.lblTopText.Size = new System.Drawing.Size(386, 40);
			this.lblTopText.TabIndex = 3;
			this.lblTopText.Text = "Remote devices must be in Discoverable mode for this computer to find them. For a" +
				"ssistance in making a remote device discoverable, refer to the remote device\'s d" +
				"ocumentation.";
			// 
			// lblTitle
			// 
			this.lblTitle.AutoSize = true;
			this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblTitle.Location = new System.Drawing.Point(12, 9);
			this.lblTitle.Name = "lblTitle";
			this.lblTitle.Size = new System.Drawing.Size(96, 13);
			this.lblTitle.TabIndex = 2;
			this.lblTitle.Text = "Select a device";
			// 
			// pictIcon
			// 
			this.pictIcon.Image = global::CG.Wrappers.Widcomm.Tests.Properties.Resources.Bluetooth;
			this.pictIcon.Location = new System.Drawing.Point(433, 12);
			this.pictIcon.Name = "pictIcon";
			this.pictIcon.Size = new System.Drawing.Size(50, 50);
			this.pictIcon.TabIndex = 1;
			this.pictIcon.TabStop = false;
			// 
			// btnStartStop
			// 
			this.btnStartStop.Location = new System.Drawing.Point(12, 225);
			this.btnStartStop.Name = "btnStartStop";
			this.btnStartStop.Size = new System.Drawing.Size(106, 23);
			this.btnStartStop.TabIndex = 2;
			this.btnStartStop.Text = "Start search";
			this.btnStartStop.UseVisualStyleBackColor = true;
			this.btnStartStop.Click += new System.EventHandler(this.btnStartStop_Click);
			// 
			// progressBar1
			// 
			this.progressBar1.Location = new System.Drawing.Point(12, 209);
			this.progressBar1.MarqueeAnimationSpeed = 40;
			this.progressBar1.Name = "progressBar1";
			this.progressBar1.Size = new System.Drawing.Size(471, 10);
			this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Marquee;
			this.progressBar1.TabIndex = 3;
			this.progressBar1.Visible = false;
			// 
			// listView1
			// 
			this.listView1.HideSelection = false;
			this.listView1.LargeImageList = this.imageList1;
			this.listView1.Location = new System.Drawing.Point(12, 73);
			this.listView1.MultiSelect = false;
			this.listView1.Name = "listView1";
			this.listView1.OwnerDraw = true;
			this.listView1.ShowItemToolTips = true;
			this.listView1.Size = new System.Drawing.Size(471, 134);
			this.listView1.TabIndex = 4;
			this.listView1.UseCompatibleStateImageBehavior = false;
			this.listView1.DrawItem += new System.Windows.Forms.DrawListViewItemEventHandler(this.listView1_DrawItem);
			this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
			// 
			// imageList1
			// 
			this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
			this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
			this.imageList1.Images.SetKeyName(0, "Computer");
			this.imageList1.Images.SetKeyName(1, "Misc");
			this.imageList1.Images.SetKeyName(2, "Phone");
			this.imageList1.Images.SetKeyName(3, "Audio");
			this.imageList1.Images.SetKeyName(4, "LanAccess");
			this.imageList1.Images.SetKeyName(5, "Imaging");
			this.imageList1.Images.SetKeyName(6, "Peripheral");
			this.imageList1.Images.SetKeyName(7, "Unspecified");
			// 
			// btnCredits
			// 
			this.btnCredits.Location = new System.Drawing.Point(15, 330);
			this.btnCredits.Name = "btnCredits";
			this.btnCredits.Size = new System.Drawing.Size(75, 23);
			this.btnCredits.TabIndex = 5;
			this.btnCredits.Text = "Icons credits";
			this.btnCredits.UseVisualStyleBackColor = true;
			this.btnCredits.Click += new System.EventHandler(this.btnCredits_Click);
			// 
			// btnSelect
			// 
			this.btnSelect.Enabled = false;
			this.btnSelect.Location = new System.Drawing.Point(380, 225);
			this.btnSelect.Name = "btnSelect";
			this.btnSelect.Size = new System.Drawing.Size(103, 23);
			this.btnSelect.TabIndex = 6;
			this.btnSelect.Text = "Select this device";
			this.btnSelect.UseVisualStyleBackColor = true;
			this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
			// 
			// InquiryWindow
			// 
			this.AcceptButton = this.btnSelect;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(495, 365);
			this.Controls.Add(this.btnSelect);
			this.Controls.Add(this.btnCredits);
			this.Controls.Add(this.listView1);
			this.Controls.Add(this.progressBar1);
			this.Controls.Add(this.btnStartStop);
			this.Controls.Add(this.pnlTop);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "InquiryWindow";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Bluetooth Device Selection";
			this.Load += new System.EventHandler(this.InquiryWindow_Load);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.InquiryWindow_FormClosing);
			this.pnlTop.ResumeLayout(false);
			this.pnlTop.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictIcon)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel pnlTop;
		private System.Windows.Forms.PictureBox pictIcon;
		private System.Windows.Forms.Label lblTopText;
		private System.Windows.Forms.Label lblTitle;
		private System.Windows.Forms.Button btnStartStop;
		private System.Windows.Forms.ProgressBar progressBar1;
		private System.Windows.Forms.ListView listView1;
		private System.Windows.Forms.Button btnCredits;
		private System.Windows.Forms.ImageList imageList1;
		private System.ComponentModel.BackgroundWorker backgroundWorker1;
		private System.Windows.Forms.Button btnSelect;
	}
}