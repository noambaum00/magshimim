using System.CodeDom.Compiler;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.Resources;
using System.Runtime.CompilerServices;

namespace AlienClient.Properties
{
	[GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
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
					resourceMan = new ResourceManager("AlienClient.Properties.Resources", typeof(Resources).Assembly);
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

		internal static Bitmap DZQDU7636SXLKK3HZ43BQYTUCA => (Bitmap)ResourceManager.GetObject("DZQDU7636SXLKK3HZ43BQYTUCA", resourceCulture);

		internal static Bitmap et02 => (Bitmap)ResourceManager.GetObject("et02", resourceCulture);

		internal static Bitmap insta => (Bitmap)ResourceManager.GetObject("insta", resourceCulture);

		internal static Bitmap insta2 => (Bitmap)ResourceManager.GetObject("insta2", resourceCulture);

		internal static Bitmap insta3 => (Bitmap)ResourceManager.GetObject("insta3", resourceCulture);

		internal Resources()
		{
		}
	}
}
