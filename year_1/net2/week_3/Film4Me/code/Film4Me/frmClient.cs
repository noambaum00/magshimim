using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Drawing;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;
using Film4Me.Properties;

namespace Film4Me
{
	public class frmClient : Form
	{
		private Dictionary<string, Action<string>> responseHandlers;

		private IContainer components;

		private Panel pnlRequest;

		private Panel pnlResponse;

		private TextBox txtCountryRequest;

		private TextBox txtEndYearRequest;

		private TextBox txtStartYearRequest;

		private Label lblCountryRequest;

		private Label lblEndYearRequest;

		private Label lblStartYearRequest;

		private Label lblGenreRequset;

		private PictureBox picFullLogo;

		private Button btnRequest;

		private Label lblGenresResponse;

		private Label lblMovieName;

		private PictureBox picMovieImage;

		private Label lblDirectorsResponse;

		private Label lblActorsResponse;

		private Label lblRatingResponse;

		private Label lblCountriesResponse;

		private Label lblMovieRating;

		private Label lblMovieCoutries;

		private Label lblMovieActors;

		private Label lblMovieDirectors;

		private Label lblMovieGenres;

		private ComboBox cboGenreRequest;

		private Label lblMaxRating;

		public frmClient()
		{
			InitializeComponent();
			ComboBox.ObjectCollection items = cboGenreRequest.Items;
			object[] items2 = new string[21]
			{
				"", "Biography", "Thriller", "History", "Family", "Mystery", "War", "Sci-Fi", "Animation", "Comedy",
				"Crime", "Music", "Sport", "Drama", "Western", "Musical", "Horror", "Action", "Adventure", "Romance",
				"Fantasy"
			};
			items.AddRange(items2);
			responseHandlers = new Dictionary<string, Action<string>>();
			responseHandlers["MOVIEDATA"] = HandleMovieData;
			responseHandlers["ERROR"] = HandleError;
		}

		private void HandleMovieData(string data)
		{
			string arg = "";
			string text = "";
			string text2 = "";
			string text3 = "";
			string text4 = "";
			int num = 0;
			float num2 = 0f;
			Image image = null;
			Regex regex = new Regex("(?<name>.*?):(?<value>.*)");
			string[] array = data.Split('&');
			foreach (string input in array)
			{
				Match match = regex.Match(input);
				string value = match.Groups["name"].Value;
				string value2 = match.Groups["value"].Value;
				switch (value)
				{
				case "name":
					arg = GetContentBetweenQuotes(value2);
					break;
				case "directors":
					text = GetContentBetweenQuotes(value2);
					break;
				case "actors":
					text2 = GetContentBetweenQuotes(value2);
					break;
				case "countries":
					text3 = GetContentBetweenQuotes(value2);
					break;
				case "genres":
					text4 = GetContentBetweenQuotes(value2);
					break;
				case "year":
					num = int.Parse(value2);
					break;
				case "rating":
					num2 = float.Parse(value2);
					break;
				case "imageurl":
					try
					{
						using WebClient webClient = new WebClient();
						string contentBetweenQuotes = GetContentBetweenQuotes(value2);
						image = Image.FromStream(webClient.OpenRead(contentBetweenQuotes));
					}
					catch
					{
						image = Resources.http_error;
					}
					break;
				}
			}
			foreach (Control control in pnlResponse.Controls)
			{
				control.Visible = true;
			}
			lblMovieName.Text = $"{arg} ({num})";
			lblMovieRating.Text = num2.ToString();
			lblMovieGenres.Text = string.Join(", ", text4.Split(','));
			lblMovieDirectors.Text = string.Join(", ", text.Split(','));
			lblMovieActors.Text = string.Join(", ", text2.Split(','));
			lblMovieCoutries.Text = string.Join(", ", text3.Split(','));
			picMovieImage.Image = image;
		}

		private void HandleError(string data)
		{
			string contentBetweenQuotes = GetContentBetweenQuotes(data);
			foreach (Control control in pnlResponse.Controls)
			{
				control.Visible = false;
			}
			if (contentBetweenQuotes.ToLower() == "no movie found")
			{
				picMovieImage.Image = Resources.movie_not_found;
				picMovieImage.Visible = true;
			}
			MessageBox.Show(contentBetweenQuotes, "Error", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}

		private void DisableForm()
		{
			pnlRequest.Enabled = false;
		}

		private void SendRequest()
		{
			string text = "";
			string text2 = "";
			string text3 = "";
			try
			{
				string genre = cboGenreRequest.Text;
				text = txtStartYearRequest.Text;
				text2 = txtEndYearRequest.Text;
				text3 = txtCountryRequest.Text;
				GetMovie getMovie = new GetMovie(genre, text, text2, text3);
				Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				socket.Connect(new IPEndPoint(IPAddress.Parse(ConfigurationManager.AppSettings["serverAddress"]), int.Parse(ConfigurationManager.AppSettings["serverPort"])));
				socket.Send(Encoding.ASCII.GetBytes(getMovie.ToString()));
				byte[] array = new byte[1024];
				socket.Receive(array);
				socket.Shutdown(SocketShutdown.Both);
				socket.Close();
				string @string = Encoding.ASCII.GetString(array);
				Match match = new Regex("(?<type>.*?)#(?<data>.*)").Match(@string);
				responseHandlers[match.Groups["type"].Value](match.Groups["data"].Value);
			}
			catch
			{
				DisableForm();
			}
		}

		private string GetContentBetweenQuotes(string data)
		{
			return new Regex("\"(?<content>.*)\"").Match(data).Groups["content"].Value;
		}

		private void btnRequest_Click(object sender, EventArgs e)
		{
			SendRequest();
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Film4Me.frmClient));
			this.pnlRequest = new System.Windows.Forms.Panel();
			this.cboGenreRequest = new System.Windows.Forms.ComboBox();
			this.btnRequest = new System.Windows.Forms.Button();
			this.picFullLogo = new System.Windows.Forms.PictureBox();
			this.lblCountryRequest = new System.Windows.Forms.Label();
			this.lblEndYearRequest = new System.Windows.Forms.Label();
			this.lblStartYearRequest = new System.Windows.Forms.Label();
			this.lblGenreRequset = new System.Windows.Forms.Label();
			this.txtCountryRequest = new System.Windows.Forms.TextBox();
			this.txtEndYearRequest = new System.Windows.Forms.TextBox();
			this.txtStartYearRequest = new System.Windows.Forms.TextBox();
			this.pnlResponse = new System.Windows.Forms.Panel();
			this.lblMaxRating = new System.Windows.Forms.Label();
			this.lblMovieRating = new System.Windows.Forms.Label();
			this.lblMovieCoutries = new System.Windows.Forms.Label();
			this.lblMovieActors = new System.Windows.Forms.Label();
			this.lblMovieDirectors = new System.Windows.Forms.Label();
			this.lblMovieGenres = new System.Windows.Forms.Label();
			this.lblRatingResponse = new System.Windows.Forms.Label();
			this.lblCountriesResponse = new System.Windows.Forms.Label();
			this.lblActorsResponse = new System.Windows.Forms.Label();
			this.lblDirectorsResponse = new System.Windows.Forms.Label();
			this.lblGenresResponse = new System.Windows.Forms.Label();
			this.lblMovieName = new System.Windows.Forms.Label();
			this.picMovieImage = new System.Windows.Forms.PictureBox();
			this.pnlRequest.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)this.picFullLogo).BeginInit();
			this.pnlResponse.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)this.picMovieImage).BeginInit();
			base.SuspendLayout();
			this.pnlRequest.Controls.Add(this.cboGenreRequest);
			this.pnlRequest.Controls.Add(this.btnRequest);
			this.pnlRequest.Controls.Add(this.picFullLogo);
			this.pnlRequest.Controls.Add(this.lblCountryRequest);
			this.pnlRequest.Controls.Add(this.lblEndYearRequest);
			this.pnlRequest.Controls.Add(this.lblStartYearRequest);
			this.pnlRequest.Controls.Add(this.lblGenreRequset);
			this.pnlRequest.Controls.Add(this.txtCountryRequest);
			this.pnlRequest.Controls.Add(this.txtEndYearRequest);
			this.pnlRequest.Controls.Add(this.txtStartYearRequest);
			this.pnlRequest.Dock = System.Windows.Forms.DockStyle.Top;
			this.pnlRequest.Location = new System.Drawing.Point(0, 0);
			this.pnlRequest.Name = "pnlRequest";
			this.pnlRequest.Size = new System.Drawing.Size(524, 151);
			this.pnlRequest.TabIndex = 0;
			this.cboGenreRequest.FormattingEnabled = true;
			this.cboGenreRequest.Location = new System.Drawing.Point(10, 95);
			this.cboGenreRequest.Name = "cboGenreRequest";
			this.cboGenreRequest.Size = new System.Drawing.Size(120, 21);
			this.cboGenreRequest.Sorted = true;
			this.cboGenreRequest.TabIndex = 10;
			this.btnRequest.Location = new System.Drawing.Point(140, 120);
			this.btnRequest.Name = "btnRequest";
			this.btnRequest.Size = new System.Drawing.Size(245, 25);
			this.btnRequest.TabIndex = 9;
			this.btnRequest.Text = "Get new film suggestion!";
			this.btnRequest.UseVisualStyleBackColor = true;
			this.btnRequest.Click += new System.EventHandler(btnRequest_Click);
			this.picFullLogo.Image = Film4Me.Properties.Resources.full_logo;
			this.picFullLogo.Location = new System.Drawing.Point(10, 5);
			this.picFullLogo.Name = "picFullLogo";
			this.picFullLogo.Size = new System.Drawing.Size(250, 60);
			this.picFullLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.picFullLogo.TabIndex = 8;
			this.picFullLogo.TabStop = false;
			this.lblCountryRequest.AutoSize = true;
			this.lblCountryRequest.Font = new System.Drawing.Font("Microsoft Sans Serif", 12f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 177);
			this.lblCountryRequest.Location = new System.Drawing.Point(390, 70);
			this.lblCountryRequest.Name = "lblCountryRequest";
			this.lblCountryRequest.Size = new System.Drawing.Size(64, 20);
			this.lblCountryRequest.TabIndex = 7;
			this.lblCountryRequest.Text = "Country";
			this.lblEndYearRequest.AutoSize = true;
			this.lblEndYearRequest.Font = new System.Drawing.Font("Microsoft Sans Serif", 12f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 177);
			this.lblEndYearRequest.Location = new System.Drawing.Point(265, 70);
			this.lblEndYearRequest.Name = "lblEndYearRequest";
			this.lblEndYearRequest.Size = new System.Drawing.Size(65, 20);
			this.lblEndYearRequest.TabIndex = 6;
			this.lblEndYearRequest.Text = "To Year";
			this.lblStartYearRequest.AutoSize = true;
			this.lblStartYearRequest.Font = new System.Drawing.Font("Microsoft Sans Serif", 12f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 177);
			this.lblStartYearRequest.Location = new System.Drawing.Point(140, 70);
			this.lblStartYearRequest.Name = "lblStartYearRequest";
			this.lblStartYearRequest.Size = new System.Drawing.Size(43, 20);
			this.lblStartYearRequest.TabIndex = 5;
			this.lblStartYearRequest.Text = "Year";
			this.lblGenreRequset.AutoSize = true;
			this.lblGenreRequset.Font = new System.Drawing.Font("Microsoft Sans Serif", 12f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 177);
			this.lblGenreRequset.Location = new System.Drawing.Point(10, 70);
			this.lblGenreRequset.Name = "lblGenreRequset";
			this.lblGenreRequset.Size = new System.Drawing.Size(54, 20);
			this.lblGenreRequset.TabIndex = 4;
			this.lblGenreRequset.Text = "Genre";
			this.txtCountryRequest.Location = new System.Drawing.Point(390, 95);
			this.txtCountryRequest.Name = "txtCountryRequest";
			this.txtCountryRequest.Size = new System.Drawing.Size(120, 20);
			this.txtCountryRequest.TabIndex = 3;
			this.txtEndYearRequest.Location = new System.Drawing.Point(265, 95);
			this.txtEndYearRequest.Name = "txtEndYearRequest";
			this.txtEndYearRequest.Size = new System.Drawing.Size(120, 20);
			this.txtEndYearRequest.TabIndex = 2;
			this.txtStartYearRequest.Location = new System.Drawing.Point(140, 95);
			this.txtStartYearRequest.Name = "txtStartYearRequest";
			this.txtStartYearRequest.Size = new System.Drawing.Size(120, 20);
			this.txtStartYearRequest.TabIndex = 1;
			this.pnlResponse.BackColor = System.Drawing.SystemColors.Window;
			this.pnlResponse.Controls.Add(this.lblMaxRating);
			this.pnlResponse.Controls.Add(this.lblMovieRating);
			this.pnlResponse.Controls.Add(this.lblMovieCoutries);
			this.pnlResponse.Controls.Add(this.lblMovieActors);
			this.pnlResponse.Controls.Add(this.lblMovieDirectors);
			this.pnlResponse.Controls.Add(this.lblMovieGenres);
			this.pnlResponse.Controls.Add(this.lblRatingResponse);
			this.pnlResponse.Controls.Add(this.lblCountriesResponse);
			this.pnlResponse.Controls.Add(this.lblActorsResponse);
			this.pnlResponse.Controls.Add(this.lblDirectorsResponse);
			this.pnlResponse.Controls.Add(this.lblGenresResponse);
			this.pnlResponse.Controls.Add(this.lblMovieName);
			this.pnlResponse.Controls.Add(this.picMovieImage);
			this.pnlResponse.Dock = System.Windows.Forms.DockStyle.Top;
			this.pnlResponse.Location = new System.Drawing.Point(0, 151);
			this.pnlResponse.Name = "pnlResponse";
			this.pnlResponse.Size = new System.Drawing.Size(524, 325);
			this.pnlResponse.TabIndex = 1;
			this.lblMaxRating.AutoSize = true;
			this.lblMaxRating.BackColor = System.Drawing.SystemColors.Window;
			this.lblMaxRating.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblMaxRating.ForeColor = System.Drawing.Color.Gray;
			this.lblMaxRating.Location = new System.Drawing.Point(293, 106);
			this.lblMaxRating.Name = "lblMaxRating";
			this.lblMaxRating.Size = new System.Drawing.Size(27, 15);
			this.lblMaxRating.TabIndex = 12;
			this.lblMaxRating.Text = "/ 10";
			this.lblMaxRating.Visible = false;
			this.lblMovieRating.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieRating.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25f, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, 0);
			this.lblMovieRating.Location = new System.Drawing.Point(265, 104);
			this.lblMovieRating.Name = "lblMovieRating";
			this.lblMovieRating.Size = new System.Drawing.Size(35, 25);
			this.lblMovieRating.TabIndex = 11;
			this.lblMovieRating.Visible = false;
			this.lblMovieCoutries.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieCoutries.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblMovieCoutries.Location = new System.Drawing.Point(310, 260);
			this.lblMovieCoutries.Name = "lblMovieCoutries";
			this.lblMovieCoutries.Size = new System.Drawing.Size(200, 35);
			this.lblMovieCoutries.TabIndex = 10;
			this.lblMovieCoutries.Visible = false;
			this.lblMovieActors.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieActors.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblMovieActors.Location = new System.Drawing.Point(310, 220);
			this.lblMovieActors.Name = "lblMovieActors";
			this.lblMovieActors.Size = new System.Drawing.Size(200, 35);
			this.lblMovieActors.TabIndex = 9;
			this.lblMovieActors.Visible = false;
			this.lblMovieDirectors.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieDirectors.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblMovieDirectors.Location = new System.Drawing.Point(310, 180);
			this.lblMovieDirectors.Name = "lblMovieDirectors";
			this.lblMovieDirectors.Size = new System.Drawing.Size(200, 35);
			this.lblMovieDirectors.TabIndex = 8;
			this.lblMovieDirectors.Visible = false;
			this.lblMovieGenres.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieGenres.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblMovieGenres.Location = new System.Drawing.Point(310, 140);
			this.lblMovieGenres.Name = "lblMovieGenres";
			this.lblMovieGenres.Size = new System.Drawing.Size(200, 35);
			this.lblMovieGenres.TabIndex = 7;
			this.lblMovieGenres.Visible = false;
			this.lblRatingResponse.Image = Film4Me.Properties.Resources.rating_star;
			this.lblRatingResponse.Location = new System.Drawing.Point(240, 100);
			this.lblRatingResponse.Name = "lblRatingResponse";
			this.lblRatingResponse.Size = new System.Drawing.Size(25, 25);
			this.lblRatingResponse.TabIndex = 6;
			this.lblRatingResponse.Visible = false;
			this.lblCountriesResponse.AutoSize = true;
			this.lblCountriesResponse.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblCountriesResponse.Location = new System.Drawing.Point(240, 260);
			this.lblCountriesResponse.Name = "lblCountriesResponse";
			this.lblCountriesResponse.Size = new System.Drawing.Size(62, 15);
			this.lblCountriesResponse.TabIndex = 5;
			this.lblCountriesResponse.Text = "Countries:";
			this.lblCountriesResponse.Visible = false;
			this.lblActorsResponse.AutoSize = true;
			this.lblActorsResponse.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblActorsResponse.Location = new System.Drawing.Point(240, 220);
			this.lblActorsResponse.Name = "lblActorsResponse";
			this.lblActorsResponse.Size = new System.Drawing.Size(43, 15);
			this.lblActorsResponse.TabIndex = 4;
			this.lblActorsResponse.Text = "Actors:";
			this.lblActorsResponse.Visible = false;
			this.lblDirectorsResponse.AutoSize = true;
			this.lblDirectorsResponse.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblDirectorsResponse.Location = new System.Drawing.Point(240, 180);
			this.lblDirectorsResponse.Name = "lblDirectorsResponse";
			this.lblDirectorsResponse.Size = new System.Drawing.Size(59, 15);
			this.lblDirectorsResponse.TabIndex = 3;
			this.lblDirectorsResponse.Text = "Directors:";
			this.lblDirectorsResponse.Visible = false;
			this.lblGenresResponse.AutoSize = true;
			this.lblGenresResponse.Font = new System.Drawing.Font("Microsoft Sans Serif", 9f);
			this.lblGenresResponse.Location = new System.Drawing.Point(240, 140);
			this.lblGenresResponse.Name = "lblGenresResponse";
			this.lblGenresResponse.Size = new System.Drawing.Size(50, 15);
			this.lblGenresResponse.TabIndex = 2;
			this.lblGenresResponse.Text = "Genres:";
			this.lblGenresResponse.Visible = false;
			this.lblMovieName.BackColor = System.Drawing.SystemColors.Window;
			this.lblMovieName.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75f, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, 177);
			this.lblMovieName.Location = new System.Drawing.Point(240, 20);
			this.lblMovieName.Name = "lblMovieName";
			this.lblMovieName.Size = new System.Drawing.Size(270, 70);
			this.lblMovieName.TabIndex = 1;
			this.lblMovieName.Visible = false;
			this.picMovieImage.Location = new System.Drawing.Point(10, 20);
			this.picMovieImage.Name = "picMovieImage";
			this.picMovieImage.Size = new System.Drawing.Size(220, 280);
			this.picMovieImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.picMovieImage.TabIndex = 0;
			this.picMovieImage.TabStop = false;
			this.picMovieImage.Visible = false;
			base.AutoScaleDimensions = new System.Drawing.SizeF(6f, 13f);
			base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			base.ClientSize = new System.Drawing.Size(524, 461);
			base.Controls.Add(this.pnlResponse);
			base.Controls.Add(this.pnlRequest);
			base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
			base.Name = "frmClient";
			this.pnlRequest.ResumeLayout(false);
			this.pnlRequest.PerformLayout();
			((System.ComponentModel.ISupportInitialize)this.picFullLogo).EndInit();
			this.pnlResponse.ResumeLayout(false);
			this.pnlResponse.PerformLayout();
			((System.ComponentModel.ISupportInitialize)this.picMovieImage).EndInit();
			base.ResumeLayout(false);
		}
	}
}
