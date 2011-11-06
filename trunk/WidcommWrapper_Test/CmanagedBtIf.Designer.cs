namespace CG.Wrappers.Widcomm.Tests
{
	partial class CManagedBtIf_Form
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btn2_ShowInquiryWindow = new System.Windows.Forms.Button();
            this.btn2_StopInquiry = new System.Windows.Forms.Button();
            this.btn2_StartInquiry = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.chk1_TrackStackStatusChange = new System.Windows.Forms.CheckBox();
            this.btn1_IsStackServerUp = new System.Windows.Forms.Button();
            this.btn1_IsDeviceReady = new System.Windows.Forms.Button();
            this.btn1_IsBtwapiFound = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.btn3_StartDiscoveryAdvanced = new System.Windows.Forms.Button();
            this.msk3_Address = new System.Windows.Forms.MaskedTextBox();
            this.btn3_StartDiscoverySimple = new System.Windows.Forms.Button();
            this.btn4_BoundQuery = new System.Windows.Forms.Button();
            this.msk4_Address = new System.Windows.Forms.MaskedTextBox();
            this.msk4_Pin = new System.Windows.Forms.MaskedTextBox();
            this.btn4_Bound = new System.Windows.Forms.Button();
            this.btn4_UnBound = new System.Windows.Forms.Button();
            this.btn5_GetServicesNames = new System.Windows.Forms.Button();
            this.btn5_GetBTWVersion = new System.Windows.Forms.Button();
            this.btn5_GetSDKVersion = new System.Windows.Forms.Button();
            this.btn5_GetExtendedError = new System.Windows.Forms.Button();
            this.btn5_GetLocalDeviceName = new System.Windows.Forms.Button();
            this.btn6_Connect = new System.Windows.Forms.Button();
            this.msk6_Address = new System.Windows.Forms.MaskedTextBox();
            this.btn6_Disconnect = new System.Windows.Forms.Button();
            this.btn6_Initialize = new System.Windows.Forms.Button();
            this.msk6_Handle = new System.Windows.Forms.MaskedTextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btn3_GetLastResults = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btn2_ShowInquiryWindow);
            this.groupBox2.Controls.Add(this.btn2_StopInquiry);
            this.groupBox2.Controls.Add(this.btn2_StartInquiry);
            this.groupBox2.Location = new System.Drawing.Point(3, 143);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(171, 117);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "2. Inquiry";
            // 
            // btn2_ShowInquiryWindow
            // 
            this.btn2_ShowInquiryWindow.Location = new System.Drawing.Point(6, 86);
            this.btn2_ShowInquiryWindow.Name = "btn2_ShowInquiryWindow";
            this.btn2_ShowInquiryWindow.Size = new System.Drawing.Size(158, 23);
            this.btn2_ShowInquiryWindow.TabIndex = 5;
            this.btn2_ShowInquiryWindow.Text = "Inquiry window";
            this.toolTip1.SetToolTip(this.btn2_ShowInquiryWindow, "Show sample inquity window");
            this.btn2_ShowInquiryWindow.UseVisualStyleBackColor = true;
            this.btn2_ShowInquiryWindow.Click += new System.EventHandler(this.btn2_ShowInquiryWindow_Click);
            // 
            // btn2_StopInquiry
            // 
            this.btn2_StopInquiry.Enabled = false;
            this.btn2_StopInquiry.Location = new System.Drawing.Point(6, 48);
            this.btn2_StopInquiry.Name = "btn2_StopInquiry";
            this.btn2_StopInquiry.Size = new System.Drawing.Size(158, 23);
            this.btn2_StopInquiry.TabIndex = 4;
            this.btn2_StopInquiry.Text = "Stop inquiry";
            this.toolTip1.SetToolTip(this.btn2_StopInquiry, "This function stops a running inquiry.");
            this.btn2_StopInquiry.UseVisualStyleBackColor = true;
            this.btn2_StopInquiry.Click += new System.EventHandler(this.btn2_StopInquiry_Click);
            // 
            // btn2_StartInquiry
            // 
            this.btn2_StartInquiry.Location = new System.Drawing.Point(6, 19);
            this.btn2_StartInquiry.Name = "btn2_StartInquiry";
            this.btn2_StartInquiry.Size = new System.Drawing.Size(158, 23);
            this.btn2_StartInquiry.TabIndex = 0;
            this.btn2_StartInquiry.Text = "Start inquiry";
            this.toolTip1.SetToolTip(this.btn2_StartInquiry, "This function starts the Bluetooth device inquiry procedure.");
            this.btn2_StartInquiry.UseVisualStyleBackColor = true;
            this.btn2_StartInquiry.Click += new System.EventHandler(this.btn2_StartInquiry_Click);
            // 
            // textBox1
            // 
            this.textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBox1.Location = new System.Drawing.Point(358, 0);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(690, 544);
            this.textBox1.TabIndex = 1;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.chk1_TrackStackStatusChange);
            this.groupBox1.Controls.Add(this.btn1_IsStackServerUp);
            this.groupBox1.Controls.Add(this.btn1_IsDeviceReady);
            this.groupBox1.Controls.Add(this.btn1_IsBtwapiFound);
            this.groupBox1.Location = new System.Drawing.Point(3, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(171, 134);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "1. Preliminary";
            // 
            // chk1_TrackStackStatusChange
            // 
            this.chk1_TrackStackStatusChange.AutoSize = true;
            this.chk1_TrackStackStatusChange.Location = new System.Drawing.Point(6, 110);
            this.chk1_TrackStackStatusChange.Name = "chk1_TrackStackStatusChange";
            this.chk1_TrackStackStatusChange.Size = new System.Drawing.Size(158, 17);
            this.chk1_TrackStackStatusChange.TabIndex = 19;
            this.chk1_TrackStackStatusChange.Text = "Track stack status changes";
            this.chk1_TrackStackStatusChange.UseVisualStyleBackColor = true;
            this.chk1_TrackStackStatusChange.CheckedChanged += new System.EventHandler(this.chk1_TrackStackStatusChange_CheckedChanged);
            // 
            // btn1_IsStackServerUp
            // 
            this.btn1_IsStackServerUp.Location = new System.Drawing.Point(6, 48);
            this.btn1_IsStackServerUp.Name = "btn1_IsStackServerUp";
            this.btn1_IsStackServerUp.Size = new System.Drawing.Size(158, 23);
            this.btn1_IsStackServerUp.TabIndex = 18;
            this.btn1_IsStackServerUp.Text = "Is stack server up?";
            this.toolTip1.SetToolTip(this.btn1_IsStackServerUp, "This function checks to see if the Bluetooth stack server is up.");
            this.btn1_IsStackServerUp.UseVisualStyleBackColor = true;
            this.btn1_IsStackServerUp.Click += new System.EventHandler(this.btn1_IsStackServerUp_Click);
            // 
            // btn1_IsDeviceReady
            // 
            this.btn1_IsDeviceReady.Location = new System.Drawing.Point(6, 77);
            this.btn1_IsDeviceReady.Name = "btn1_IsDeviceReady";
            this.btn1_IsDeviceReady.Size = new System.Drawing.Size(158, 23);
            this.btn1_IsDeviceReady.TabIndex = 17;
            this.btn1_IsDeviceReady.Text = "Is device ready?";
            this.toolTip1.SetToolTip(this.btn1_IsDeviceReady, "This function verifies that the application is connected to the stack server, and" +
                    " that the stack server and Bluetooth device are ready to accept commands.");
            this.btn1_IsDeviceReady.UseVisualStyleBackColor = true;
            this.btn1_IsDeviceReady.Click += new System.EventHandler(this.btn1_IsDeviceReady_Click);
            // 
            // btn1_IsBtwapiFound
            // 
            this.btn1_IsBtwapiFound.Location = new System.Drawing.Point(6, 19);
            this.btn1_IsBtwapiFound.Name = "btn1_IsBtwapiFound";
            this.btn1_IsBtwapiFound.Size = new System.Drawing.Size(158, 23);
            this.btn1_IsBtwapiFound.TabIndex = 0;
            this.btn1_IsBtwapiFound.Text = "Is btwapi.dll found?";
            this.toolTip1.SetToolTip(this.btn1_IsBtwapiFound, "This function check if btwapi.dll library is loadable on the system.");
            this.btn1_IsBtwapiFound.UseVisualStyleBackColor = true;
            this.btn1_IsBtwapiFound.Click += new System.EventHandler(this.btn1_IsBtwapiFound_Click);
            // 
            // btn3_StartDiscoveryAdvanced
            // 
            this.btn3_StartDiscoveryAdvanced.Location = new System.Drawing.Point(6, 73);
            this.btn3_StartDiscoveryAdvanced.Name = "btn3_StartDiscoveryAdvanced";
            this.btn3_StartDiscoveryAdvanced.Size = new System.Drawing.Size(158, 23);
            this.btn3_StartDiscoveryAdvanced.TabIndex = 17;
            this.btn3_StartDiscoveryAdvanced.Text = "Start discovery advanced";
            this.toolTip1.SetToolTip(this.btn3_StartDiscoveryAdvanced, "This function requests a service discovery for a specific device.");
            this.btn3_StartDiscoveryAdvanced.UseVisualStyleBackColor = true;
            this.btn3_StartDiscoveryAdvanced.Click += new System.EventHandler(this.btn3_StartDiscoveryAdvanced_Click);
            // 
            // msk3_Address
            // 
            this.msk3_Address.Location = new System.Drawing.Point(60, 19);
            this.msk3_Address.Mask = "&&:&&:&&:&&:&&:&&";
            this.msk3_Address.Name = "msk3_Address";
            this.msk3_Address.Size = new System.Drawing.Size(104, 20);
            this.msk3_Address.TabIndex = 15;
            this.msk3_Address.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip1.SetToolTip(this.msk3_Address, "Enter bluetooth addres of device to discover services");
            // 
            // btn3_StartDiscoverySimple
            // 
            this.btn3_StartDiscoverySimple.Location = new System.Drawing.Point(6, 45);
            this.btn3_StartDiscoverySimple.Name = "btn3_StartDiscoverySimple";
            this.btn3_StartDiscoverySimple.Size = new System.Drawing.Size(158, 23);
            this.btn3_StartDiscoverySimple.TabIndex = 12;
            this.btn3_StartDiscoverySimple.Text = "Start discovery simple";
            this.toolTip1.SetToolTip(this.btn3_StartDiscoverySimple, "This function requests a service discovery for a specific device.");
            this.btn3_StartDiscoverySimple.UseVisualStyleBackColor = true;
            this.btn3_StartDiscoverySimple.Click += new System.EventHandler(this.btn3_StartDiscoverySimple_Click);
            // 
            // btn4_BoundQuery
            // 
            this.btn4_BoundQuery.Location = new System.Drawing.Point(6, 45);
            this.btn4_BoundQuery.Name = "btn4_BoundQuery";
            this.btn4_BoundQuery.Size = new System.Drawing.Size(158, 23);
            this.btn4_BoundQuery.TabIndex = 3;
            this.btn4_BoundQuery.Text = "Bound query";
            this.toolTip1.SetToolTip(this.btn4_BoundQuery, "This function tests if the indicated device is already paired with the local devi" +
                    "ce.");
            this.btn4_BoundQuery.UseVisualStyleBackColor = true;
            this.btn4_BoundQuery.Click += new System.EventHandler(this.btn4_BoundQuery_Click);
            // 
            // msk4_Address
            // 
            this.msk4_Address.Location = new System.Drawing.Point(60, 19);
            this.msk4_Address.Mask = "&&:&&:&&:&&:&&:&&";
            this.msk4_Address.Name = "msk4_Address";
            this.msk4_Address.Size = new System.Drawing.Size(104, 20);
            this.msk4_Address.TabIndex = 17;
            this.msk4_Address.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip1.SetToolTip(this.msk4_Address, "Enter bluetooth addres of device to discover services");
            // 
            // msk4_Pin
            // 
            this.msk4_Pin.Location = new System.Drawing.Point(60, 76);
            this.msk4_Pin.Mask = "0000";
            this.msk4_Pin.Name = "msk4_Pin";
            this.msk4_Pin.Size = new System.Drawing.Size(38, 20);
            this.msk4_Pin.TabIndex = 20;
            this.msk4_Pin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip1.SetToolTip(this.msk4_Pin, "Enter bluetooth addres of device to discover services");
            // 
            // btn4_Bound
            // 
            this.btn4_Bound.Location = new System.Drawing.Point(104, 74);
            this.btn4_Bound.Name = "btn4_Bound";
            this.btn4_Bound.Size = new System.Drawing.Size(60, 23);
            this.btn4_Bound.TabIndex = 11;
            this.btn4_Bound.Text = "Bound";
            this.toolTip1.SetToolTip(this.btn4_Bound, "This function initiates the bonding procedure with the specified device. This fun" +
                    "ction will block for up to 1 minute while the security functions at the lower le" +
                    "vels perform the bonding procedure.");
            this.btn4_Bound.UseVisualStyleBackColor = true;
            this.btn4_Bound.Click += new System.EventHandler(this.btn4_Bound_Click);
            // 
            // btn4_UnBound
            // 
            this.btn4_UnBound.Location = new System.Drawing.Point(6, 103);
            this.btn4_UnBound.Name = "btn4_UnBound";
            this.btn4_UnBound.Size = new System.Drawing.Size(157, 23);
            this.btn4_UnBound.TabIndex = 13;
            this.btn4_UnBound.Text = "Unbound";
            this.toolTip1.SetToolTip(this.btn4_UnBound, "This function deletes the bond between the devices.");
            this.btn4_UnBound.UseVisualStyleBackColor = true;
            this.btn4_UnBound.Click += new System.EventHandler(this.btn4_UnBound_Click);
            // 
            // btn5_GetServicesNames
            // 
            this.btn5_GetServicesNames.Location = new System.Drawing.Point(6, 77);
            this.btn5_GetServicesNames.Name = "btn5_GetServicesNames";
            this.btn5_GetServicesNames.Size = new System.Drawing.Size(159, 23);
            this.btn5_GetServicesNames.TabIndex = 23;
            this.btn5_GetServicesNames.Text = "Get service names";
            this.toolTip1.SetToolTip(this.btn5_GetServicesNames, "This function is used to query to the local Bluetooth Stack for registered servic" +
                    "es.");
            this.btn5_GetServicesNames.UseVisualStyleBackColor = true;
            this.btn5_GetServicesNames.Click += new System.EventHandler(this.btn5_GetServicesNames_Click);
            // 
            // btn5_GetBTWVersion
            // 
            this.btn5_GetBTWVersion.Location = new System.Drawing.Point(6, 135);
            this.btn5_GetBTWVersion.Name = "btn5_GetBTWVersion";
            this.btn5_GetBTWVersion.Size = new System.Drawing.Size(159, 23);
            this.btn5_GetBTWVersion.TabIndex = 22;
            this.btn5_GetBTWVersion.Text = "Get BTW version";
            this.toolTip1.SetToolTip(this.btn5_GetBTWVersion, "This method is used to get BTW version information.");
            this.btn5_GetBTWVersion.UseVisualStyleBackColor = true;
            this.btn5_GetBTWVersion.Click += new System.EventHandler(this.btn5_GetBTWVersion_Click);
            // 
            // btn5_GetSDKVersion
            // 
            this.btn5_GetSDKVersion.Location = new System.Drawing.Point(6, 106);
            this.btn5_GetSDKVersion.Name = "btn5_GetSDKVersion";
            this.btn5_GetSDKVersion.Size = new System.Drawing.Size(159, 23);
            this.btn5_GetSDKVersion.TabIndex = 21;
            this.btn5_GetSDKVersion.Text = "Get SDK version";
            this.toolTip1.SetToolTip(this.btn5_GetSDKVersion, "This method is used to get SDK version information.");
            this.btn5_GetSDKVersion.UseVisualStyleBackColor = true;
            this.btn5_GetSDKVersion.Click += new System.EventHandler(this.btn5_GetSDKVersion_Click);
            // 
            // btn5_GetExtendedError
            // 
            this.btn5_GetExtendedError.Location = new System.Drawing.Point(6, 19);
            this.btn5_GetExtendedError.Name = "btn5_GetExtendedError";
            this.btn5_GetExtendedError.Size = new System.Drawing.Size(159, 23);
            this.btn5_GetExtendedError.TabIndex = 20;
            this.btn5_GetExtendedError.Text = "Get extended error";
            this.toolTip1.SetToolTip(this.btn5_GetExtendedError, "This function returns the object’s last-error code.");
            this.btn5_GetExtendedError.UseVisualStyleBackColor = true;
            this.btn5_GetExtendedError.Click += new System.EventHandler(this.btn5_GetExtendedError_Click);
            // 
            // btn5_GetLocalDeviceName
            // 
            this.btn5_GetLocalDeviceName.Location = new System.Drawing.Point(6, 48);
            this.btn5_GetLocalDeviceName.Name = "btn5_GetLocalDeviceName";
            this.btn5_GetLocalDeviceName.Size = new System.Drawing.Size(159, 23);
            this.btn5_GetLocalDeviceName.TabIndex = 19;
            this.btn5_GetLocalDeviceName.Text = "Get local device name";
            this.toolTip1.SetToolTip(this.btn5_GetLocalDeviceName, "This function retrieves the local device name to the caller’s buffer.");
            this.btn5_GetLocalDeviceName.UseVisualStyleBackColor = true;
            this.btn5_GetLocalDeviceName.Click += new System.EventHandler(this.btn5_GetLocalDeviceName_Click);
            // 
            // btn6_Connect
            // 
            this.btn6_Connect.Location = new System.Drawing.Point(6, 81);
            this.btn6_Connect.Name = "btn6_Connect";
            this.btn6_Connect.Size = new System.Drawing.Size(158, 23);
            this.btn6_Connect.TabIndex = 3;
            this.btn6_Connect.Text = "Connect";
            this.toolTip1.SetToolTip(this.btn6_Connect, "This function connect headphone");
            this.btn6_Connect.UseVisualStyleBackColor = true;
            this.btn6_Connect.Click += new System.EventHandler(this.btn6_Connect_Click);
            // 
            // msk6_Address
            // 
            this.msk6_Address.Location = new System.Drawing.Point(60, 55);
            this.msk6_Address.Mask = "&&:&&:&&:&&:&&:&&";
            this.msk6_Address.Name = "msk6_Address";
            this.msk6_Address.Size = new System.Drawing.Size(104, 20);
            this.msk6_Address.TabIndex = 17;
            this.msk6_Address.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip1.SetToolTip(this.msk6_Address, "Enter bluetooth addres of device to discover services");
            // 
            // btn6_Disconnect
            // 
            this.btn6_Disconnect.Location = new System.Drawing.Point(95, 109);
            this.btn6_Disconnect.Name = "btn6_Disconnect";
            this.btn6_Disconnect.Size = new System.Drawing.Size(69, 23);
            this.btn6_Disconnect.TabIndex = 19;
            this.btn6_Disconnect.Text = "Disconnect";
            this.toolTip1.SetToolTip(this.btn6_Disconnect, "This function disconnect headphone");
            this.btn6_Disconnect.UseVisualStyleBackColor = true;
            this.btn6_Disconnect.Click += new System.EventHandler(this.btn6_Disconnect_Click);
            // 
            // btn6_Initialize
            // 
            this.btn6_Initialize.Location = new System.Drawing.Point(6, 19);
            this.btn6_Initialize.Name = "btn6_Initialize";
            this.btn6_Initialize.Size = new System.Drawing.Size(158, 23);
            this.btn6_Initialize.TabIndex = 20;
            this.btn6_Initialize.Text = "Initialize";
            this.toolTip1.SetToolTip(this.btn6_Initialize, "This function initialize headphone class to handle status changed notifications");
            this.btn6_Initialize.UseVisualStyleBackColor = true;
            this.btn6_Initialize.Click += new System.EventHandler(this.btn6_Initialize_Click);
            // 
            // msk6_Handle
            // 
            this.msk6_Handle.Location = new System.Drawing.Point(53, 111);
            this.msk6_Handle.Mask = "####";
            this.msk6_Handle.Name = "msk6_Handle";
            this.msk6_Handle.Size = new System.Drawing.Size(36, 20);
            this.msk6_Handle.TabIndex = 22;
            this.msk6_Handle.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.toolTip1.SetToolTip(this.msk6_Handle, "Enter bluetooth addres of device to discover services");
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.btn3_StartDiscoveryAdvanced);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.msk3_Address);
            this.groupBox3.Controls.Add(this.btn3_GetLastResults);
            this.groupBox3.Controls.Add(this.btn3_StartDiscoverySimple);
            this.groupBox3.Location = new System.Drawing.Point(3, 266);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(171, 131);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "3. Discovery";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 13);
            this.label1.TabIndex = 16;
            this.label1.Text = "Address:";
            // 
            // btn3_GetLastResults
            // 
            this.btn3_GetLastResults.Location = new System.Drawing.Point(6, 102);
            this.btn3_GetLastResults.Name = "btn3_GetLastResults";
            this.btn3_GetLastResults.Size = new System.Drawing.Size(158, 23);
            this.btn3_GetLastResults.TabIndex = 14;
            this.btn3_GetLastResults.Text = "Last discovery result";
            this.btn3_GetLastResults.UseVisualStyleBackColor = true;
            this.btn3_GetLastResults.Click += new System.EventHandler(this.btnGetResultsCount_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.groupBox6);
            this.panel1.Controls.Add(this.groupBox5);
            this.panel1.Controls.Add(this.groupBox4);
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.groupBox3);
            this.panel1.Controls.Add(this.groupBox2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(358, 544);
            this.panel1.TabIndex = 4;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.msk6_Handle);
            this.groupBox6.Controls.Add(this.label4);
            this.groupBox6.Controls.Add(this.btn6_Initialize);
            this.groupBox6.Controls.Add(this.btn6_Disconnect);
            this.groupBox6.Controls.Add(this.label5);
            this.groupBox6.Controls.Add(this.msk6_Address);
            this.groupBox6.Controls.Add(this.btn6_Connect);
            this.groupBox6.Location = new System.Drawing.Point(180, 176);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(171, 138);
            this.groupBox6.TabIndex = 15;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "6. Headphone";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 114);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(44, 13);
            this.label4.TabIndex = 21;
            this.label4.Text = "Handle:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 58);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(48, 13);
            this.label5.TabIndex = 18;
            this.label5.Text = "Address:";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btn5_GetServicesNames);
            this.groupBox5.Controls.Add(this.btn5_GetBTWVersion);
            this.groupBox5.Controls.Add(this.btn5_GetSDKVersion);
            this.groupBox5.Controls.Add(this.btn5_GetExtendedError);
            this.groupBox5.Controls.Add(this.btn5_GetLocalDeviceName);
            this.groupBox5.Location = new System.Drawing.Point(180, 3);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(171, 167);
            this.groupBox5.TabIndex = 14;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "5. Misc";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.msk4_Pin);
            this.groupBox4.Controls.Add(this.label3);
            this.groupBox4.Controls.Add(this.label2);
            this.groupBox4.Controls.Add(this.msk4_Address);
            this.groupBox4.Controls.Add(this.btn4_UnBound);
            this.groupBox4.Controls.Add(this.btn4_Bound);
            this.groupBox4.Controls.Add(this.btn4_BoundQuery);
            this.groupBox4.Location = new System.Drawing.Point(3, 403);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(171, 133);
            this.groupBox4.TabIndex = 13;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "4. Bounding";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 79);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(55, 13);
            this.label3.TabIndex = 19;
            this.label3.Text = "PIN code:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 22);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(48, 13);
            this.label2.TabIndex = 18;
            this.label2.Text = "Address:";
            // 
            // CManagedBtIf_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1048, 544);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.panel1);
            this.Name = "CManagedBtIf_Form";
            this.Text = "CmanagedBtIf";
            this.groupBox2.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Button btn2_StartInquiry;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.Button btn1_IsBtwapiFound;
		private System.Windows.Forms.ToolTip toolTip1;
		private System.Windows.Forms.CheckBox chk1_TrackStackStatusChange;
		private System.Windows.Forms.Button btn1_IsStackServerUp;
		private System.Windows.Forms.Button btn1_IsDeviceReady;
		private System.Windows.Forms.Button btn2_ShowInquiryWindow;
		private System.Windows.Forms.Button btn2_StopInquiry;
		private System.Windows.Forms.GroupBox groupBox3;
		private System.Windows.Forms.MaskedTextBox msk3_Address;
		private System.Windows.Forms.Button btn3_GetLastResults;
		private System.Windows.Forms.Button btn3_StartDiscoverySimple;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.Button btn3_StartDiscoveryAdvanced;
		private System.Windows.Forms.GroupBox groupBox4;
		private System.Windows.Forms.Button btn4_UnBound;
		private System.Windows.Forms.Button btn4_Bound;
		private System.Windows.Forms.Button btn4_BoundQuery;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.MaskedTextBox msk4_Address;
		private System.Windows.Forms.MaskedTextBox msk4_Pin;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.GroupBox groupBox5;
		private System.Windows.Forms.Button btn5_GetServicesNames;
		private System.Windows.Forms.Button btn5_GetBTWVersion;
		private System.Windows.Forms.Button btn5_GetSDKVersion;
		private System.Windows.Forms.Button btn5_GetExtendedError;
		private System.Windows.Forms.Button btn5_GetLocalDeviceName;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Button btn6_Disconnect;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.MaskedTextBox msk6_Address;
        private System.Windows.Forms.Button btn6_Connect;
        private System.Windows.Forms.MaskedTextBox msk6_Handle;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btn6_Initialize;
	}
}