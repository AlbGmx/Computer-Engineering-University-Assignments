using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SchoolSync
{
    public partial class BlockedAppsForm : Form
    {
        public BlockedAppsForm()
        {
            InitializeComponent();
            PopulateListView();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Utils.AddApplicationList();
            PopulateListView();
        }

        private void BlockedAppsForm_Load(object sender, EventArgs e)
        {
            this.ControlBox = false;
        }

        private void PopulateListView()
        {
            listView1.Items.Clear();
            Dictionary<string, int> dictionary = Utils.getDictiorany();

            listView1.Columns.Add("Application", -2, HorizontalAlignment.Left);

            foreach (var kvp in dictionary)
            {
                ListViewItem item = new ListViewItem(kvp.Key);
                listView1.Items.Add(item);
            }
        }

        private string GetSelectedItem()
        {
            List<string> selectedItems = new List<string>();

            foreach (ListViewItem item in listView1.SelectedItems)
            {
                string key = item.Text;
                selectedItems.Add(key);
            }

            return string.Join(Environment.NewLine, selectedItems);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Utils.RemoveAppFromList(GetSelectedItem());
            PopulateListView();
            Utils.SaveApplicationList();
        }
    }
}
