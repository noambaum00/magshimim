using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.Resources;
using System.Runtime.CompilerServices;

namespace Film4Me.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "15.0.0.0")]
	[DebuggerNonUserCode]
	[CompilerGenerated]
	internal class Resources
	{
		private static ResourceManager resourceMan;

		private static CultureInfo resourceCulture;

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static ResourceManager ResourceManager
		{
			get
			{
				if (resourceMan == null)
				{
					resourceMan = new ResourceManager("Film4Me.Properties.Resources", typeof(Resources).Assembly);
				}
				return resourceMan;
			}
		}

		[EditorBrowsable(EditorBrowsableState.Advanced)]
		internal static CultureInfo Culture
		{
			get
			{
				return resourceCulture;
			}
			set
			{
				resourceCulture = value;
			}
		}

		internal static Bitmap full_logo => (Bitmap)ResourceManager.GetObject("full_logo", resourceCulture);

		internal static Bitmap http_error => (Bitmap)ResourceManager.GetObject("http_error", resourceCulture);

		internal static Bitmap movie_not_found => (Bitmap)ResourceManager.GetObject("movie_not_found", resourceCulture);

		internal static Bitmap rating_star => (Bitmap)ResourceManager.GetObject("rating_star", resourceCulture);

		internal Resources()
		{
		}
	}
}
