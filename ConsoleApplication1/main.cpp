
#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include <ShlObj.h>

#include <opencv2\opencv.hpp>

std::vector<std::string>  splitpath(const std::string filepath);
std::string getFrameFilePath(std::string videoFileName, int frameNo);
int getVideolength(const cv::VideoCapture &video);
int getCurrentFrameNumber(const cv::VideoCapture &video);
std::vector<std::string> splitpath(const std::string& str, const std::set<char> delimiters);
void CreateFolder(const char * path);
bool saveFrame(cv::VideoCapture video, cv::Mat frame, std::string videoFilename);
std::string getFrameFilepath(cv::VideoCapture video, std::string videoFilename);


std::string filename1 = "E:\\6.Testdata\\Video\\frex\\2013-04-06 192000.avi";		// Jobb
//	std::string filename = "C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi";	// Hemma



void main(void)
{
	TCHAR s[100];
	GetCurrentDirectory(100, s);

//---
	// QStandardPaths Class
	// http://doc.qt.io/qt-5/qstandardpaths.html

	LPWSTR wszPath = NULL;
	HRESULT hr;
	hr = SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_CREATE, NULL, &wszPath);
	std::cout << wszPath << std::endl; //this is the mem space?
	std::cout << &wszPath << std::endl; //what's in the mem space, pointer to another mem space
	std::cout << *(&wszPath) << std::endl; //dereference the pointer?
//---

	std::string str1 = "123456";
	std::string str2 = "123";
	std::string content(str1.length(), '0'); // create a string with only "0"
	content.replace(str1.length()-str2.length(), str1.length()-1, str2); // replace with str2


	std::string str = "C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi";
	//std::string str = "C:/2.Testdata/Video/frex/2013-04-06 192000.avi";
	std::cout << "Hej" << std::endl;
	std::cout << str.c_str() << std::endl;

	char *drive, *dir, *fname, *ext;
	drive = (char *)malloc(100 * sizeof(char));
	dir = (char *)malloc(100 * sizeof(char));
	fname = (char *)malloc(100 * sizeof(char));
	ext = (char *)malloc(100 * sizeof(char));
	_splitpath_s(str.c_str(), drive, 100, dir, 100, fname, 100, ext, 100);

	std::cout << drive << std::endl;
	std::cout << dir << std::endl;
	std::cout << fname << std::endl;
	std::cout << ext << std::endl;
	getchar();

	std::set<char> delims{ '\\' };
	std::vector<std::string> path = splitpath("C:\\2.Testdata\\Video\\frex\\2013-04-06 192000.avi", delims);
	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i].c_str() << std::endl;
	}
	getchar();


// -- Test image
	cv::Mat img(100,100,CV_8UC3);
	img = cv::Scalar(0,0,255);

	cv::imshow("Test", img);
	cv::waitKey();
	bool ok = cv::imwrite("C:\\Temp\\aaa\\img02.tif", img);


// -- Test video
	cv::VideoCapture cap(filename1); // open videofile
	for (int i = 0; i < 20; i++)
	{
		cv::Mat frame;
		cap >> frame;
		imshow("movie-play-btn", frame);
		ok = saveFrame(cap, frame, filename1);
		if (cv::waitKey(30) >= 0)
			break;
	}


	CreateFolder("c:\\xxaa");
	std::string str3 = "C:\\xxaa55";
	CreateDirectoryA(str3.c_str(), NULL);
	CreateDirectoryA("c:\\xxaa44", NULL);

}

std::vector<std::string> splitpath(const std::string filepath)
{
	std::vector<std::string> result;

	char *drive, *dir, *fname, *ext;
	drive = (char *)malloc(255 * sizeof(char)); // "C:"
	dir =	(char *)malloc(255 * sizeof(char)); // "\2.Testdata\Video\frex\"
	fname = (char *)malloc(255 * sizeof(char)); // "2013-04 192000"
	ext =	(char *)malloc(255 * sizeof(char)); // ".avi"
	_splitpath_s(filepath.c_str(), drive, 255, dir, 255, fname, 255, ext, 255);

	result.push_back(std::string(drive)+std::string(dir));
	result.push_back(std::string(fname)+std::string(ext));
	return result;
}

// Returns filepath (path + filename) for saving frame as image
std::string getFrameFilePath(std::string videoFileName, int frameNo)
{
	std::string str = "";

	return str;
}

int getVideolength(const cv::VideoCapture &video)
{
	double d = video.get(CV_CAP_PROP_FRAME_COUNT);
	return int(d);
}

int getCurrentFrameNumber(const cv::VideoCapture &video)
{
	double d = video.get(CV_CAP_PROP_POS_FRAMES);
	return int(d);
}

std::vector<std::string> splitpath(const std::string& str, const std::set<char> delimiters)
{
	std::vector<std::string> result;

	char const* pch = str.c_str();
	char const* start = pch;
	for (; *pch; ++pch)
	{
		if (delimiters.find(*pch) != delimiters.end())
		{
			if (start != pch)
			{
				std::string str(start, pch);
				result.push_back(str);

			}
			else
			{
				result.push_back("");
			}
			start = pch + 1;
		}
	}
	result.push_back(start);

	return result;
}


void CreateFolder(const char * path)
{
	if (!CreateDirectoryA(path, NULL))
	{
		return;
	}
}

bool saveFrame(cv::VideoCapture video, cv::Mat frame, std::string videoFilename)
{
	std::string filepathFrame = getFrameFilepath(video, videoFilename);

	bool ok = cv::imwrite(filepathFrame, frame);
	return ok;
}

std::string getFrameFilepath(cv::VideoCapture video, std::string videoFilename)
{
	std::string str1 = std::to_string(getVideolength(video));
	std::string str2 = std::to_string(getCurrentFrameNumber(video));
	std::string number(str1.length(), '0'); // create a string with only "0"
	number.replace(str1.length() - str2.length(), str1.length() - 1, str2); // replace with str2

	std::vector<std::string> result = splitpath(filename1);

	std::string path = result[0] + "export\\";
	std::string filename = result[1] + "_" + number + ".tif";

	CreateFolder(path.c_str());

	return path+filename;
}

