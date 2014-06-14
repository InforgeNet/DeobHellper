using System.Windows.Forms;
/*
 * Created by SharpDevelop.
 * User: V0K3
 * Date: 26/04/2014
 * Time: 22.36
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace DeobHellper
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.gbxAuto = new System.Windows.Forms.GroupBox();
			this.btnAutoDeob = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.btnBrowseTblAuto = new System.Windows.Forms.Button();
			this.txtFileTblAuto = new System.Windows.Forms.TextBox();
			this.btnBrowseAuto = new System.Windows.Forms.Button();
			this.txtFileAuto = new System.Windows.Forms.TextBox();
			this.lblToy = new System.Windows.Forms.Label();
			this.gbxAuto.SuspendLayout();
			this.SuspendLayout();
			// 
			// gbxAuto
			// 
			this.gbxAuto.Controls.Add(this.btnAutoDeob);
			this.gbxAuto.Controls.Add(this.label2);
			this.gbxAuto.Controls.Add(this.btnBrowseTblAuto);
			this.gbxAuto.Controls.Add(this.txtFileTblAuto);
			this.gbxAuto.Controls.Add(this.btnBrowseAuto);
			this.gbxAuto.Controls.Add(this.txtFileAuto);
			this.gbxAuto.Location = new System.Drawing.Point(12, 12);
			this.gbxAuto.Name = "gbxAuto";
			this.gbxAuto.Size = new System.Drawing.Size(303, 169);
			this.gbxAuto.TabIndex = 13;
			this.gbxAuto.TabStop = false;
			this.gbxAuto.Text = "Automatic Deobfuscator: ";
			// 
			// btnAutoDeob
			// 
			this.btnAutoDeob.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnAutoDeob.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnAutoDeob.ForeColor = System.Drawing.Color.Red;
			this.btnAutoDeob.Location = new System.Drawing.Point(79, 116);
			this.btnAutoDeob.Name = "btnAutoDeob";
			this.btnAutoDeob.Size = new System.Drawing.Size(136, 37);
			this.btnAutoDeob.TabIndex = 12;
			this.btnAutoDeob.Text = "Deob!";
			this.btnAutoDeob.UseVisualStyleBackColor = true;
			this.btnAutoDeob.Click += new System.EventHandler(this.BtnAutoDeobClick);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(14, 59);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(41, 13);
			this.label2.TabIndex = 19;
			this.label2.Text = "Tbl file:";
			// 
			// btnBrowseTblAuto
			// 
			this.btnBrowseTblAuto.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnBrowseTblAuto.ForeColor = System.Drawing.Color.Violet;
			this.btnBrowseTblAuto.Location = new System.Drawing.Point(244, 75);
			this.btnBrowseTblAuto.Name = "btnBrowseTblAuto";
			this.btnBrowseTblAuto.Size = new System.Drawing.Size(44, 23);
			this.btnBrowseTblAuto.TabIndex = 15;
			this.btnBrowseTblAuto.Text = ". . .";
			this.btnBrowseTblAuto.UseVisualStyleBackColor = true;
			this.btnBrowseTblAuto.Click += new System.EventHandler(this.BtnBrowseTblAutoClick);
			// 
			// txtFileTblAuto
			// 
			this.txtFileTblAuto.Location = new System.Drawing.Point(14, 77);
			this.txtFileTblAuto.Name = "txtFileTblAuto";
			this.txtFileTblAuto.Size = new System.Drawing.Size(224, 20);
			this.txtFileTblAuto.TabIndex = 14;
			// 
			// btnBrowseAuto
			// 
			this.btnBrowseAuto.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
			this.btnBrowseAuto.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
			this.btnBrowseAuto.Location = new System.Drawing.Point(244, 28);
			this.btnBrowseAuto.Name = "btnBrowseAuto";
			this.btnBrowseAuto.Size = new System.Drawing.Size(44, 23);
			this.btnBrowseAuto.TabIndex = 13;
			this.btnBrowseAuto.Text = ". . .";
			this.btnBrowseAuto.UseVisualStyleBackColor = true;
			this.btnBrowseAuto.Click += new System.EventHandler(this.BtnBrowseAutoClick);
			// 
			// txtFileAuto
			// 
			this.txtFileAuto.Location = new System.Drawing.Point(14, 30);
			this.txtFileAuto.Name = "txtFileAuto";
			this.txtFileAuto.Size = new System.Drawing.Size(224, 20);
			this.txtFileAuto.TabIndex = 12;
			// 
			// lblToy
			// 
			this.lblToy.AutoSize = true;
			this.lblToy.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblToy.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblToy.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
			this.lblToy.Location = new System.Drawing.Point(36, 189);
			this.lblToy.Name = "lblToy";
			this.lblToy.Size = new System.Drawing.Size(256, 16);
			this.lblToy.TabIndex = 20;
			this.lblToy.Text = "FUCK THE TOY MOTHERFUCKERS";
			this.lblToy.Click += new System.EventHandler(this.LblToyClick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Black;
			this.ClientSize = new System.Drawing.Size(326, 185);
			this.Controls.Add(this.lblToy);
			this.Controls.Add(this.gbxAuto);
			this.ForeColor = System.Drawing.Color.White;
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.Opacity = 0.9D;
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "DeobHellper 0.3 #:..:t";
			this.TopMost = true;
			this.gbxAuto.ResumeLayout(false);
			this.gbxAuto.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label lblToy;
		private System.Windows.Forms.TextBox txtFileAuto;
		private System.Windows.Forms.Button btnBrowseAuto;
		private System.Windows.Forms.TextBox txtFileTblAuto;
		private System.Windows.Forms.Button btnBrowseTblAuto;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btnAutoDeob;
		private System.Windows.Forms.GroupBox gbxAuto;
	}
}
