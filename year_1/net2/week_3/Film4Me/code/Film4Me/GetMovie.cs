namespace Film4Me
{
	internal class GetMovie
	{
		private string genre;

		private string startYear;

		private string endYear;

		private string country;

		public GetMovie(string genre, string startYear, string endYear, string country)
		{
			this.genre = genre;
			this.startYear = startYear;
			this.endYear = endYear;
			this.country = country;
		}

		public override string ToString()
		{
			return $"GETMOVIE#genre:{genre}&year:{startYear}-{endYear}&country:{country}";
		}
	}
}
