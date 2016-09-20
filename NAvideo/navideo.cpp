#include <navideo.h>
#include <QMediaPlaylist>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>


NAvideo::NAvideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	
	
	QMediaPlaylist *playlist;
	playlist = new QMediaPlaylist;
	//playlist->addMedia(QUrl::fromLocalFile("D:\\6.Testdata\\Video\\egna filmer\\MVI_3690.MOV"));
	//playlist->addMedia(QUrl::fromLocalFile("E:\\WORK\\testdata\\exempelvideo\\testfilmer\\MOV00031.MP4"));
	playlist->addMedia(QUrl::fromLocalFile("C:\\2.Testdata\\Video\\egna filmer\\MVI_3691.MOV"));
	playlist->setCurrentIndex(1);

	QMediaPlayer *player;
	player = new QMediaPlayer;
	player->setPlaylist(playlist);


	//QVideoWidget *videoWidget;
	//videoWidget = new QVideoWidget;
	//player->setVideoOutput(videoWidget);
	//videoWidget->show();

	player->setVideoOutput(ui.moviewidget);
	ui.moviewidget->show();

	player->play();

	//ui->centralWidget = 

}

NAvideo::~NAvideo()
{

}
