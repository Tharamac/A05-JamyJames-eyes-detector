#pragma once
#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

namespace FormDemo {
	using namespace cv;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fIleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fIleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fIleToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(880, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fIleToolStripMenuItem
			// 
			this->fIleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fIleToolStripMenuItem->Name = L"fIleToolStripMenuItem";
			this->fIleToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fIleToolStripMenuItem->Text = L"FIle";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(294, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(574, 379);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Image files(*.jpg; *.jpeg; *.png) | *.jpg; *.jpeg; *.png";
			// 
			// groupBox1
			// 
			this->groupBox1->AutoSize = true;
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(276, 379);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Image Description";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MainForm::groupBox1_Enter);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Resolution : ";
			this->label4->Visible = false;
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name : ";
			this->label2->Visible = false;
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Eyes Coordinate :";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(880, 418);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->label1->Visible = true;
			this->label2->Visible = true;
			//this->label3->Visible = true;
			this->label4->Visible = true;
			this->label2->Text = "Name : "+openFileDialog1->SafeFileName;
			//this->label3->Text += openFileDialog1->FileName;
			
			Bitmap^ bmp = gcnew Bitmap(openFileDialog1->FileName);
			// Lock Bitmap Bits
			Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
			System::Drawing::Imaging::BitmapData^ bmpData =
				bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite,
					bmp->PixelFormat);

			// Using OpenCV: Create Image Header
			IplImage* pImage = cvCreateImageHeader(cvSize(bmp->Width, bmp->Height), IPL_DEPTH_8U, 3);

			// Map IplImage to the address of the Bitmap image.
			pImage->imageData = (char*)(void*)bmpData->Scan0;
			pImage->widthStep = bmpData->Stride;
			
			cv::CascadeClassifier eyesCascade("haarcascade_eye.xml"), facesCascade("haarcascade_frontalcatface.xml");
			cv::Mat img = cv::cvarrToMat(pImage);
			/*if (pImage->width < 400 || pImage->height < 400) {
				cv::resize(img,img, cv::Size(), 3,3);
			}*/
			this->label4->Text = gcnew System::String(( "Resolution : "+ std::to_string(pImage->width) + " x " + std::to_string(pImage->width)).c_str());
			this->label1->Text = "Eyes Coordinate : ";
			// Do OpenCV function Here 

			Mat frame_gray;
			cvtColor(img, frame_gray, COLOR_BGR2GRAY);
			imshow("555", frame_gray);
			waitKey(0);
			equalizeHist(frame_gray, frame_gray);
			imshow("555", frame_gray);
			
		
				std::vector<cv::Rect> eyes;
				if (pImage->width < 500 || pImage->height < 500) {
					eyesCascade.detectMultiScale(img, eyes, 1.3, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(50,30));
				}else
					eyesCascade.detectMultiScale(img, eyes, 1.1, 5, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(100, 100));
			//	rectangle(img, cv::Point(faces[j].x, faces[j].y), cv::Point(faces[j].x + faces[j].width , faces[j].y +faces[j].height), Scalar(0, 0, 0), 2);
				for (size_t i = 0; i < eyes.size(); i++)
				{
					//Rect *r = (Rect *)cvGetSeqElem((CvSeq *)eyes[i],i);
					// Extract eye from the image.
					Mat eye = img(eyes[i]);
			
					//cv::waitKey(0);
					Mat grayeye;
					cvtColor(eye, grayeye, CV_BGR2GRAY);
					// Split eye image into 3 channels.	
					cv::imshow("gray", grayeye);
					
					std::vector<Mat>bgr(3);
					split(eye, bgr);
					//threshold(grayeye, grayeye, 90,255,THRESH_BINARY);
					//bitwise_not(grayeye, grayeye);
					//cv::imshow("thres", grayeye);
					//waitKey(0);
				
					GaussianBlur(grayeye, grayeye, cv::Size(3, 3), 1.5, 1.5);
					cv::imshow("blur", grayeye);
					waitKey(0);

					std::vector<Vec3f> circles;

					/// Apply the Hough Transform to find the circles
					HoughCircles(grayeye, circles, CV_HOUGH_GRADIENT, 1, 30 , 9 ,1, 0, 17);

					// Simple red eye detector
					Mat mask = (bgr[2] > 150)& (bgr[2] > (bgr[1] + bgr[0]));

					// Clean mask -- 1) File holes 2) Dilate (expand) mask
					std::cout << circles.size();
					 /// Draw the circles detected
					for (size_t i = 0; i < 1 /*circles.size()*/; i++)
					{
						cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
						int radius = cvRound(circles[i][2]);
						// circle center
						circle(eye, center, 2, Scalar(0, 255, 0), -1, 8, 0);
						// circle outline
						circle(eye, center, radius, Scalar(0, 0, 255), 2, 8, 0);
					}


					// Calculate the mean channel by averaging
					// the green and blue channels

					Mat mean = (bgr[0] + bgr[1]) / 2;
					mean.copyTo(bgr[2], mask);
					mean.copyTo(bgr[0], mask);
					mean.copyTo(bgr[1], mask);
	
					// Merge channels
					Mat eyeOut;
					cv::merge(bgr, eyeOut);
					rectangle(img, cv::Point(eyes[i].x, eyes[i].y), cv::Point(eyes[i].x + eyes[i].width, eyes[i].y + eyes[i].height), Scalar(255, 255, 255), 3);

					System::String^ new_str = "\n\n  Eye #";
					new_str += gcnew System::String((std::to_string(i+1) +"\n      Start: ( " + std::to_string(eyes[i].x) + " , " + std::to_string(eyes[i].y) + " )").c_str()); 
					new_str += gcnew System::String(("\n      End: ( " + std::to_string(eyes[i].x + eyes[i].width) + " , " + std::to_string(eyes[i].y + eyes[i].height) + " )" ).c_str()); 
			
					this->label1->Text += new_str;
					// Copy the fixed eye to the output image.
					eye.copyTo(img(eyes[i]));

				}
			

				
				//IplImage copy = img;
				pImage = cvCloneImage(&(IplImage)img);
			// Release Image Header
			cvReleaseImageHeader(&pImage); 

			// Unlock Bitmap Bits
			bmp->UnlockBits(bmpData);
			pictureBox1->Image = bmp;
		}
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
