using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace DeobHellper
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}
		
		
		void BtnBrowseAutoClick(object sender, EventArgs e)
		{
			using(OpenFileDialog of = new OpenFileDialog())
			{
				of.CheckFileExists = true;
				of.Multiselect = false;
				of.Filter = "AutoIt Sources Files|*.au3";
				
				if(of.ShowDialog() == DialogResult.OK) {
					txtFileAuto.Text = of.FileName;
				}
			}
		}
		
		void BtnBrowseTblAutoClick(object sender, EventArgs e)
		{
			using(OpenFileDialog of = new OpenFileDialog())
			{
				of.CheckFileExists = true;
				of.Multiselect = false;
				of.Filter = "TBL Files|*.tbl";
				
				if(of.ShowDialog() == DialogResult.OK) {
					txtFileTblAuto.Text = of.FileName;
				}
			}
		}
		
		void BtnAutoDeobClick(object sender, EventArgs e)
		{
			if(txtFileAuto.Text.ToLower().Contains("money")) {
				this.Height = 237;
				return;
			}
			
			try
			{
				string obf, tbl, deob;
				
				obf = File.ReadAllText(txtFileAuto.Text);
				tbl = File.ReadAllText(txtFileTblAuto.Text);
				deob = AutoDeobfuscator.Deobfuscate(obf, tbl);
				
				System.IO.File.WriteAllText(txtFileAuto.Text.Replace(".au3", "") + "_deob.au3", deob);
				MessageBox.Show("Done!");
			} catch (Exception ex) {
				MessageBox.Show("Error: " + ex.Message, "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
			}
		}
		
		void LblToyClick(object sender, EventArgs e)
		{
			Process.Start("https://www.youtube.com/watch?v=VSipiuRi7Do");
		}
	}
}
