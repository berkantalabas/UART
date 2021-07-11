﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace led_uart_arduino_msp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("t");    //Seri porta "1" gönder    
            label1.Text = "ON";  //Label1'e "Led Açık" yaz
            button2.Enabled = true;    //Button2'yi tıklanabilir hale getir
            button1.Enabled = false;   //Button1'i tıklanamaz hale getir
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();  //Seri portları diziye ekleme
            foreach (string port in ports)
            comboBox1.Items.Add(port); //Seri portları comBox1' ekleme
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("m");    //Seri porta "0" gönder
            label1.Text = "OFF";//Label1'e "Led Kapalı" yaz
            button1.Enabled = true;    //Button1'i tıklanabilir hale getir
            button2.Enabled = false;   //Button2'yi tıklanamaz hale getir

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBox1.SelectedItem.ToString(); //comboBox1'de seçili olan portu port ismine ata
            serialPort1.Open(); //Seri portu aç
        }
    }
}
