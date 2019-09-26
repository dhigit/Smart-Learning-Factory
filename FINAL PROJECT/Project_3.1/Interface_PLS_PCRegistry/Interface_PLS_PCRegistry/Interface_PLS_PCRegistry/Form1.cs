using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using ACTMULTILib;
using Microsoft.Win32;

namespace Interface_PLS_PCRegistry
{
    public partial class Form1 : Form
    {
        ActEasyIFClass plc = new ActEasyIFClass();
        RegistryKey plcData_y;

        string[] yAddressName = new string[6] { "Y0", "Y1", "Y2", "Y3", "Y4", "Y5" };
        int[] yResultData = new int[6];

        public Form1()
        {
            InitializeComponent();
            ComClose.Enabled = false;
            plcData_y = Registry.CurrentUser.CreateSubKey("PLC_DATA");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Stop();
            plc.Close();
        }

        int stationNo = 1;
        private void ComOpen_Click(object sender, EventArgs e)
        {
            plc.ActLogicalStationNumber = 1;

            if (stationNo == 1)
            {
                int open = plc.Open();
                if (open != 0)
                {
                    MessageBox.Show("Communication Error!");
                }
                else
                {
                    MessageBox.Show("Communication Success!");
                    ComOpen.Enabled = false;
                    ComClose.Enabled = true;

                    timer1.Start();
                    this.WindowState = FormWindowState.Minimized;
                }
            }
        }

        private void ComClose_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            plc.Close();
            MessageBox.Show("Communication is Disconnected!");
            ComOpen.Enabled = true;
            ComClose.Enabled = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            for (int i=0; i<yAddressName.Length; i++)
            {
                plc.GetDevice(yAddressName[i], out yResultData[i]);
                plcData_y.SetValue(yAddressName[i], yResultData[i]);
            }
        }
    }
}
