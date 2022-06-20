using System;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using AlienClient.Properties;

namespace AlienClient
{
	public class Form1 : Form
	{
		private string mode = "";

		public bool active;

		public static string IP = "54.71.128.194";

		public static int PORT = 0;

		public static Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

		public static IPAddress serverAddr = IPAddress.Parse(IP);

		public static IPEndPoint endPoint;

		private IContainer components;

		private TextBox textBox1;

		private Label label1;

		private Button button1;

		private Label label2;

		private System.Windows.Forms.Timer timer1;

		private System.Windows.Forms.Timer timer2;

		private Label label3;

		private PictureBox pictureBox1;

		private Label label_finish;

		public Form1()
		{
			InitializeComponent();
			string text = "";
			/*try
			{
				text = File.ReadAllText("config.ini");
			}
			catch
			{
				MessageBox.Show("Config file not present.\nMake sure you have config.ini");
				Environment.Exit(-1);
			}
			if (text.Contains("green"))
			{
				mode = "green";
				PORT = 98;
			}
			else if (text.Contains("blue"))
			{
				mode = "blue";
				PORT = 99;
			}
			else
			{
				MessageBox.Show("Wrong config.\nPlease dont change config file");
				Environment.Exit(-1);
			}
			*/
			mode = "green";
			PORT = 98;

			endPoint = new IPEndPoint(serverAddr, PORT);
		}

		public void finish_game()
		{
			button1.Invoke((MethodInvoker)delegate
			{
				button1.Visible = false;
			});
			label1.Invoke((MethodInvoker)delegate
			{
				label1.Visible = false;
			});
			label2.Invoke((MethodInvoker)delegate
			{
				label2.Visible = false;
			});
			textBox1.Invoke((MethodInvoker)delegate
			{
				textBox1.Visible = false;
			});
			pictureBox1.Invoke((MethodInvoker)delegate
			{
				pictureBox1.Image = Resources.insta3;
			});
			label_finish.Invoke((MethodInvoker)delegate
			{
				label_finish.Visible = true;
			});
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			new Thread((ThreadStart)delegate
			{
				Thread.Sleep(100);
				byte[] recv_buffer = new byte[1024];
				byte[] array = new byte[1024];
				array = Encoding.ASCII.GetBytes(enc_full("WAK000UP"));
				sock.SendTo(array, endPoint);
				while (true)
				{
					recv_buffer = new byte[1024];
					array = new byte[1024];
					try
					{
						sock.Receive(recv_buffer);
					}
					catch (SocketException ex)
					{
						MessageBox.Show(ex.ErrorCode.ToString());
					}
					label3.Invoke((MethodInvoker)delegate
					{
						label3.Text = dec_full(Encoding.ASCII.GetString(recv_buffer));
					});
					if (Encoding.ASCII.GetString(recv_buffer).Substring(0, 3) == "ERR" && !Encoding.ASCII.GetString(recv_buffer).Contains(";"))
					{
						label1.Invoke((MethodInvoker)delegate
						{
							label1.Text = "ERR";
						});
					}
					if (dec_full(Encoding.ASCII.GetString(recv_buffer)).Contains("granted"))
					{
						label1.Invoke((MethodInvoker)delegate
						{
							label1.Text = "Initiating come back to planet Jupiter. Waiting for parameters. Countdown: 1 minute";
						});
						activateCountdown();
						string input = "";
						if (mode == "blue")
						{
							input = "FLY008location_md5=00000000000000000000000000000000,airport=nevada25.84,time=15:52,lane=earth.jup,vehicle=2554,fly";
						}
						else if (mode == "green")
						{
							input = "FLY003airport=unselected,time=00:00,lane=unknown,vehicle=0000,fly";
						}
						array = Encoding.ASCII.GetBytes(enc_full(input));
						sock.SendTo(array, endPoint);
					}
					if (Encoding.ASCII.GetString(recv_buffer).Substring(0, 3) == "YES")
					{
						break;
					}
					if (Encoding.ASCII.GetString(recv_buffer).Substring(0, 6) == "DAT009" || (mode == "green" && dec_full(Encoding.ASCII.GetString(recv_buffer)).Contains("for travel:")))
					{
						string input2 = "";
						if (mode == "blue")
						{
							input2 = "FLY008location_md5=00000000000000000000000000000000,airport=unselected,time=15:52,lane=earth.jup,vehicle=2554,fly";
						}
						else if (mode == "green")
						{
							input2 = "FLY003airport=unselected,time=00:00,lane=unknown,vehicle=0000,fly";
						}
						array = Encoding.ASCII.GetBytes(enc_full(input2));
						sock.SendTo(array, endPoint);
					}
					Thread.Sleep(100);
				}
				finish_game();
			}).Start();
		}

		public string enc_full(string input)
		{
			return input.Substring(0, 6) + decrypt_encrypt(input.Substring(6), Convert.ToInt32(input.Substring(3, 3)));
		}

		public string dec_full(string input)
		{
			return input.Substring(0, 6) + decrypt_encrypt(input.Substring(6), -1 * Convert.ToInt32(input.Substring(3, 3)));
		}

		public void activateCountdown()
		{
			active = true;
			label2.Invoke((MethodInvoker)delegate
			{
				label2.Text = "1:00";
				label2.Visible = true;
			});
			pictureBox1.Invoke((MethodInvoker)delegate
			{
				pictureBox1.Image = Resources.insta2;
			});
		}

		public string decrypt_encrypt(string input, int key)
		{
			input = input.ToLower();
			string source = "abcdefghijklmnopqrstuvwxyz";
			string text = "";
			int num = 0;
			string text2 = input;
			for (int i = 0; i < text2.Length; i++)
			{
				char c = text2[i];
				text = ((!source.Contains(c) || num % 2 != 0) ? (text + c) : (text + (char)((c - 97 + key) % 26 + 97)));
				num++;
			}
			return text;
		}

		private void button1_Click(object sender, EventArgs e)
		{
			string s = enc_full("ENT003" + textBox1.Text);
			byte[] bytes = Encoding.ASCII.GetBytes(s);
			sock.SendTo(bytes, endPoint);
			_ = new byte[1024];
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			label2.Invoke((MethodInvoker)delegate
			{
				if (label2.Text == "0:0" || label2.Text == "0:00")
				{
					label2.Text = "1:00";
					label2.Visible = false;
					pictureBox1.Invoke((MethodInvoker)delegate
					{
						pictureBox1.Image = Resources.insta;
					});
					active = false;
				}
				else
				{
					int num = Convert.ToInt32(label2.Text.Split(':')[0]) * 60 + Convert.ToInt32(label2.Text.Split(':')[1]);
					num--;
					label2.Text = num / 60 + ":" + num % 60;
					if (label2.Text.Length == 3)
					{
						label2.Text = "0:0" + label2.Text[label2.Text.Length - 1];
					}
				}
			});
			if (active)
			{
				if (BackColor == Color.Black)
				{
					BackColor = Color.Green;
				}
				else
				{
					BackColor = Color.Black;
				}
			}
		}

		private void timer2_Tick(object sender, EventArgs e)
		{
		}

		private void label2_Click(object sender, EventArgs e)
		{
		}

		private void pictureBox1_Click(object sender, EventArgs e)
		{
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && components != null)
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AlienClient.Form1));
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.button1 = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.timer2 = new System.Windows.Forms.Timer(this.components);
			this.label3 = new System.Windows.Forms.Label();
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.label_finish = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)this.pictureBox1).BeginInit();
			base.SuspendLayout();
			this.textBox1.Location = new System.Drawing.Point(146, 387);
			this.textBox1.Margin = new System.Windows.Forms.Padding(2);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(163, 20);
			this.textBox1.TabIndex = 0;
			this.label1.AutoSize = true;
			this.label1.BackColor = System.Drawing.SystemColors.ControlDark;
			this.label1.Location = new System.Drawing.Point(9, 7);
			this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(13, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "?";
			this.button1.Location = new System.Drawing.Point(210, 358);
			this.button1.Margin = new System.Windows.Forms.Padding(2);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(34, 25);
			this.button1.TabIndex = 2;
			this.button1.Text = "!";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(button1_Click);
			this.label2.AutoSize = true;
			this.label2.BackColor = System.Drawing.Color.Black;
			this.label2.Font = new System.Drawing.Font("Vivaldi", 48f, System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, 0);
			this.label2.ForeColor = System.Drawing.Color.Silver;
			this.label2.Location = new System.Drawing.Point(11, 367);
			this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(129, 76);
			this.label2.TabIndex = 5;
			this.label2.Text = "5:00";
			this.label2.Visible = false;
			this.label2.Click += new System.EventHandler(label2_Click);
			this.timer1.Enabled = true;
			this.timer1.Interval = 1000;
			this.timer1.Tick += new System.EventHandler(timer1_Tick);
			this.timer2.Tick += new System.EventHandler(timer2_Tick);
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(9, 158);
			this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(13, 13);
			this.label3.TabIndex = 6;
			this.label3.Text = "?";
			this.label3.Visible = false;
			this.pictureBox1.Image = AlienClient.Properties.Resources.insta;
			this.pictureBox1.Location = new System.Drawing.Point(10, 10);
			this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(450, 450);
			this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.pictureBox1.TabIndex = 3;
			this.pictureBox1.TabStop = false;
			this.pictureBox1.Click += new System.EventHandler(pictureBox1_Click);
			this.label_finish.AutoSize = true;
			this.label_finish.BackColor = System.Drawing.Color.Black;
			this.label_finish.Font = new System.Drawing.Font("Arial", 21.75f, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, 0);
			this.label_finish.ForeColor = System.Drawing.Color.White;
			this.label_finish.Location = new System.Drawing.Point(11, 424);
			this.label_finish.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
			this.label_finish.Name = "label_finish";
			this.label_finish.Size = new System.Drawing.Size(447, 34);
			this.label_finish.TabIndex = 7;
			this.label_finish.Text = "THANK YOU EARTH PEOPLE!!!!";
			this.label_finish.Visible = false;
			base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
			base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Black;
			base.ClientSize = new System.Drawing.Size(469, 467);
			base.Controls.Add(this.label_finish);
			base.Controls.Add(this.label2);
			base.Controls.Add(this.label3);
			base.Controls.Add(this.button1);
			base.Controls.Add(this.label1);
			base.Controls.Add(this.textBox1);
			base.Controls.Add(this.pictureBox1);
			base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
			base.Margin = new System.Windows.Forms.Padding(2);
			base.MaximizeBox = false;
			base.Name = "Form1";
			this.Text = "Alien Client";
			base.Load += new System.EventHandler(Form1_Load);
			((System.ComponentModel.ISupportInitialize)this.pictureBox1).EndInit();
			base.ResumeLayout(false);
			base.PerformLayout();
		}
	}
}
