using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace CG.Wrappers.Widcomm.Tests
{
	static class Program
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new CManagedBtIf_Form());
		}
	}
}
