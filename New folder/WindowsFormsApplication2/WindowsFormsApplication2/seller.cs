using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

using System.IO;

namespace WindowsFormsApplication2
{
    public partial class seller : Form
    {
        public seller()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] imagebt = null;


            string nam = name.Text;
            string emai = email.Text;
            string adres = adress.Text;
            string phon = phone.Text;
            string des = description.Text;
            SqlConnection con = new SqlConnection(@"Data Source=DESKTOP-IVINE6D\SQLEXPRESS;Initial Catalog=myproject;Integrated Security=True");
            con.Open();
            SqlCommand command;
            string sql;
            sql = "Insert Into seller([seller-name],[seller-email],[seller-adress],[seller-phone])values(@nam,@emi,@adres,@phon)Insert Into product([descreption])values(@des) ";
            command = new SqlCommand(sql, con);
            command.Parameters.AddWithValue("@nam", name.Text);
            command.Parameters.AddWithValue("@emi", email.Text);
            command.Parameters.AddWithValue("@adres",adress.Text);
            command.Parameters.AddWithValue("@phon", phone.Text);
            command.Parameters.AddWithValue("@des", description.Text);
            command.ExecuteNonQuery();
            command.Dispose();
            MessageBox.Show("connection sucsses");
            con.Close();
        }

        private void seller_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'myprojectDataSet.seller' table. You can move, or remove it, as needed.

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            OpenFileDialog ope = new OpenFileDialog();
            ope.Filter = "JPG Files(*.jpg)|*.jpg|Png Files(*.png)|*.png|All files(*.*) |*.*";
            if(ope.ShowDialog()==DialogResult.OK)
            {
                string pi = ope.FileName.ToString();
                picture.ImageLocation = pi;
            }
        }
    }
}
