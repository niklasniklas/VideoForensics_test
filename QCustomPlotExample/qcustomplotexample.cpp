#include "qcustomplotexample.h"

QCustomPlotExample::QCustomPlotExample(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
	ui.widget->legend->setVisible(true);
	QFont legendFont = font();  // start out with MainWindow's font..
	legendFont.setPointSize(9); // and make a bit smaller for legend
	ui.widget->legend->setFont(legendFont);
	ui.widget->legend->setBrush(QBrush(QColor(255, 255, 255, 230)));
	// by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
	ui.widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom | Qt::AlignRight);

	// setup for graph 0: key axis left, value axis bottom
	// will contain left maxwell-like function
	ui.widget->addGraph(ui.widget->yAxis, ui.widget->xAxis);
	ui.widget->graph(0)->setPen(QPen(QColor(255, 100, 0)));
	ui.widget->graph(0)->setBrush(QBrush(QPixmap("C:\\2.Testdata\\Bilder\\boldt.jpg"))); // fill with texture of specified image
	ui.widget->graph(0)->setLineStyle(QCPGraph::lsLine);
	ui.widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
	ui.widget->graph(0)->setName("Left maxwell function");

	// setup for graph 1: key axis bottom, value axis left (those are the default axes)
	// will contain bottom maxwell-like function with error bars
	ui.widget->addGraph();
	ui.widget->graph(1)->setPen(QPen(Qt::red));
	ui.widget->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
	ui.widget->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
	ui.widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
	ui.widget->graph(1)->setName("Bottom maxwell function");
	QCPErrorBars *errorBars = new QCPErrorBars(ui.widget->xAxis, ui.widget->yAxis);
	errorBars->removeFromLegend();
	errorBars->setDataPlottable(ui.widget->graph(1));

	// setup for graph 2: key axis top, value axis right
	// will contain high frequency sine with low frequency beating:
	ui.widget->addGraph(ui.widget->xAxis2, ui.widget->yAxis2);
	ui.widget->graph(2)->setPen(QPen(Qt::blue));
	ui.widget->graph(2)->setName("High frequency sine");

	// setup for graph 3: same axes as graph 2
	// will contain low frequency beating envelope of graph 2
	ui.widget->addGraph(ui.widget->xAxis2, ui.widget->yAxis2);
	QPen blueDotPen;
	blueDotPen.setColor(QColor(30, 40, 255, 150));
	blueDotPen.setStyle(Qt::DotLine);
	blueDotPen.setWidthF(4);
	ui.widget->graph(3)->setPen(blueDotPen);
	ui.widget->graph(3)->setName("Sine envelope");

	// setup for graph 4: key axis right, value axis top
	// will contain parabolically distributed data points with some random perturbance
	ui.widget->addGraph(ui.widget->yAxis2, ui.widget->xAxis2);
	ui.widget->graph(4)->setPen(QColor(50, 50, 50, 255));
	ui.widget->graph(4)->setLineStyle(QCPGraph::lsNone);
	ui.widget->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
	ui.widget->graph(4)->setName("Some random data around\na quadratic function");

	// generate data, just playing with numbers, not much to learn here:
	QVector<double> x0(25), y0(25);
	QVector<double> x1(15), y1(15), y1err(15);
	QVector<double> x2(250), y2(250);
	QVector<double> x3(250), y3(250);
	QVector<double> x4(250), y4(250);
	for (int i = 0; i<25; ++i) // data for graph 0
	{
		x0[i] = 3 * i / 25.0;
		y0[i] = qExp(-x0[i] * x0[i] * 0.8)*(x0[i] * x0[i] + x0[i]);
	}
	for (int i = 0; i<15; ++i) // data for graph 1
	{
		x1[i] = 3 * i / 15.0;;
		y1[i] = qExp(-x1[i] * x1[i])*(x1[i] * x1[i])*2.6;
		y1err[i] = y1[i] * 0.25;
	}
	for (int i = 0; i<250; ++i) // data for graphs 2, 3 and 4
	{
		x2[i] = i / 250.0 * 3 * M_PI;
		x3[i] = x2[i];
		x4[i] = i / 250.0 * 100 - 50;
		y2[i] = qSin(x2[i] * 12)*qCos(x2[i]) * 10;
		y3[i] = qCos(x3[i]) * 10;
		y4[i] = 0.01*x4[i] * x4[i] + 1.5*(rand() / (double)RAND_MAX - 0.5) + 1.5*M_PI;
	}

	// pass data points to graphs:
	ui.widget->graph(0)->setData(x0, y0);
	ui.widget->graph(1)->setData(x1, y1);
	errorBars->setData(y1err);
	ui.widget->graph(2)->setData(x2, y2);
	ui.widget->graph(3)->setData(x3, y3);
	ui.widget->graph(4)->setData(x4, y4);
	// activate top and right axes, which are invisible by default:
	ui.widget->xAxis2->setVisible(true);
	ui.widget->yAxis2->setVisible(true);
	// set ranges appropriate to show data:
	ui.widget->xAxis->setRange(0, 2.7);
	ui.widget->yAxis->setRange(0, 2.6);
	ui.widget->xAxis2->setRange(0, 3.0*M_PI);
	ui.widget->yAxis2->setRange(-70, 35);
	// set pi ticks on top axis:
	ui.widget->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
	// add title layout element:
	ui.widget->plotLayout()->insertRow(0);
	ui.widget->plotLayout()->addElement(0, 0, new QCPTextElement(ui.widget, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
	// set labels:
	ui.widget->xAxis->setLabel("Bottom axis with outward ticks");
	ui.widget->yAxis->setLabel("Left axis label");
	ui.widget->xAxis2->setLabel("Top axis label");
	ui.widget->yAxis2->setLabel("Right axis label");
	// make ticks on bottom axis go outward:
	ui.widget->xAxis->setTickLength(0, 5);
	ui.widget->xAxis->setSubTickLength(0, 3);
	// make ticks on right axis go inward and outward:
	ui.widget->yAxis2->setTickLength(3, 3);
	ui.widget->yAxis2->setSubTickLength(1, 1);

	/* Simple example
	// add two new graphs and set their look:
	ui.widget->addGraph();
	ui.widget->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
	ui.widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
	ui.widget->addGraph();
	ui.widget->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
	// generate some points of data (y0 for first, y1 for second graph):
	QVector<double> x(251), y0(251), y1(251);
	for (int i = 0; i<251; ++i)
	{
	x[i] = i;
	y0[i] = qExp(-i / 150.0)*qCos(i / 10.0); // exponentially decaying cosine
	y1[i] = qExp(-i / 150.0);              // exponential envelope
	}
	// configure right and top axis to show ticks but no labels:
	// (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
	ui.widget->xAxis2->setVisible(true);
	ui.widget->xAxis2->setTickLabels(false);
	ui.widget->yAxis2->setVisible(true);
	ui.widget->yAxis2->setTickLabels(false);
	// make left and bottom axes always transfer their ranges to right and top axes:
	connect(ui.widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui.widget->xAxis2, SLOT(setRange(QCPRange)));
	connect(ui.widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui.widget->yAxis2, SLOT(setRange(QCPRange)));
	// pass data points to graphs:
	ui.widget->graph(0)->setData(x, y0);
	ui.widget->graph(1)->setData(x, y1);
	// let the ranges scale themselves so graph 0 fits perfectly in the visible area:
	ui.widget->graph(0)->rescaleAxes();
	// same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
	ui.widget->graph(1)->rescaleAxes(true);
	// Note: we could have also just called ui.widget->rescaleAxes(); instead
	// Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
	ui.widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	*/

}

QCustomPlotExample::~QCustomPlotExample()
{

}
