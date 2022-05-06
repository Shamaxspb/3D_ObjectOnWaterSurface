#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

#include<ShaderProgram.h>

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void drawPolgyon();

const int START_WINDOW_WIDTH = 400;
const int START_WINDOW_HEIGHT = 300;

class Polygon // polygon
{
public:
	Polygon()
	{

	}

	class Point
	{
	public:
		Point() {}
		Point(float coordX, float coordY, float coordZ) //constructor
		{
			this->coordX = coordX;
			this->coordY = coordY;
			this->coordZ = coordZ;
		}

		// getters
		float GetXcomponent() { return coordX; }
		float GetYcomponent() { return coordY; }
		float GetZcomponent() { return coordZ; }
		// setters
		void SetXcomponent(float xValue) { this->coordX = xValue; }
		void SetYcomponent(float yValue) { this->coordY = yValue; }
		void SetZcomponent(float zValue) { this->coordZ = zValue; }

		void PointInfo()
		{
			cout << "Point.X:\t" << GetXcomponent()
				<< "\nPoint.Y:\t" << GetYcomponent()
				<< "\nPoint.Z:\t" << GetZcomponent() << endl << endl;
		}

		float coordX;
		float coordY;
		float coordZ; 
		//float dstnsBtwnYs = coordY + 15; // place this as Y components in points B and D
	};

	Polygon(Point pointA, Point pointB, Point pointC, Point pointD)
	{
		this->pointA = pointA;
		this->pointB = pointB;
		this->pointC = pointC;
		this->pointD = pointD;
	}

	void PolygonVerticesInfo()
	{
		cout << "=====\tPOLYGON\t=====" << endl;
		cout << "Point A" << endl;
		pointA.PointInfo();
		cout << "Point B" << endl;
		pointB.PointInfo();
		cout << "Point C" << endl;
		pointC.PointInfo();
		cout << "Point D" << endl;
		pointD.PointInfo();

	}

	Point pointA;
	Point pointB;
	Point pointC;
	Point pointD;
};
//Points::y = 10;

int main()
{
	// reading wave height doc ==============================================================================
	vector<float> waveHeight;
	auto wave_iterator = waveHeight.begin();
	fstream waveFile;
	//const unsigned int waveCount = waveHeight.size();
	
	waveFile.open("WaveHeight.txt", fstream::in);
	if (!waveFile.is_open())
	{
		cout << "ERROR\tcouldn't open WaveHeight.txt" << endl;
		return -1;
	}

	// write file to vector
	while (!waveFile.eof())
	{
		float buffer;
		waveFile >> buffer;
		waveHeight.push_back(buffer);
	}

	// waveHeight output (for TEST reasons only)
	/*for (auto wave_iterator = waveHeight.begin(); wave_iterator != waveHeight.end(); wave_iterator++)
	{
		cout << *wave_iterator << endl;
	}
	cout << "\nwaveHeight size:\t" << waveHeight.size() << endl;
	wave_iterator = waveHeight.begin();
	cout << *wave_iterator << endl;
	wave_iterator++;
	//advance(wave_iterator, 1);
	cout << *wave_iterator << endl;*/

	// initializing GLFW ====================================================================================
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// creating window
	GLFWwindow* window = glfwCreateWindow(START_WINDOW_WIDTH, START_WINDOW_HEIGHT, "Object Visualisation", NULL, NULL);
	// check window
	if (window == NULL)
	{
		cout << "ERROR\tWindow creation failed" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// check GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "ERROR:\tGLAD initialization failed" << endl;
		return -1;
	}

	// TEST FIELD +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	const float Y_LENGTH = 15;
	int timeMoment = 1;

	wave_iterator = waveHeight.begin();
	/*Polygon plg;
	plg.SetVertices(wave_iterator);
	plg.PrintValues();
	cout << "===\n";
	Polygon plg2;
	plg2.SetVertices(wave_iterator);
	plg2.PrintValues();
	cout << "===\n";
	Polygon plg3;
	plg3.SetVertices(wave_iterator);
	plg3.PrintValues();
	cout << "===\n";

	Polygon::Point::SetZcomponent(*wave_iterator);

	Polygon::Point pointA;
	pointA.SetXcomponent(timeMoment);
	pointA.SetZcomponent(*wave_iterator);
	//pointA.PointInfo();

	Polygon::Point pointB;
	pointB.SetXcomponent(timeMoment);
	//pointB.SetYcomponent();
	pointB.SetZcomponent(*wave_iterator);
	//pointB.PointInfo();

	Polygon::Point pointC;
	pointC.SetXcomponent(timeMoment);
	pointC.SetZcomponent(*wave_iterator);
	//pointC.PointInfo();

	Polygon::Point pointD;
	pointD.SetXcomponent(timeMoment);
	pointD.SetZcomponent(*wave_iterator);
	//pointD.PointInfo();

	Polygon plg(pointA, pointB, pointC, pointD);
	plg.PolygonVerticesInfo();*/

	Shader myShader("myVertexShader.vs","myFragmentShader.fs");

	float testSquareVertices[] = {
		// position			// indicies of vertices
		-0.5f,  0.5f, 0.0f,	// A - 0
		-0.5f, -0.5f, 0.0f,	// B - 1
		 0.0f,  0.5f, 0.0f, // C - 2
		 0.0f, -0.5f, 0.0f,	// D - 3
		 0.5f,  0.5f, 0.0f, // E - 4
		 0.5f, -0.5f, 0.0f	// F - 5
	};

	float testSquareIndicies[] = {
		0, 1, 3,	// triangle ABD
		0, 3, 2,	// triangle ADC
		2, 3, 5,	// triangle CDF
		2, 5, 4		// triangle CFE
	};

	// TEST FIELD -----------------------------------------------------------------------------------------------------

	// creating square (2 triangles)
	float polygonVertices[] = {
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	float polygonIndicies[] = {
		0, 1, 2,
		0, 2, 3,
		4, 0, 3,
		4, 3, 5,
		5, 6, 2,
		5, 2, 3
	};

	
	unsigned int VAO, VBO, EBO;

	// create and bind VAO
	glGenVertexArrays(1, &VAO); 
	glBindVertexArray(VAO);

	// only 1 attribute pointer since we only have position (no color, no texture)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// allocate memory in GPU and copy there data from testSquareVertices array
	glBufferData(GL_ARRAY_BUFFER, sizeof(testSquareVertices), testSquareVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// allocate memory in GPU and copy there data from testSquareIndicies array
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(testSquareIndicies), testSquareIndicies, GL_STATIC_DRAW);
	
	myShader.Use();

	// render loop ==========================================================================================
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		//glClearColor(0.63f, 0.46f, 0.84f, 1.0f);
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// render
		myShader.Use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

		// swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}

// function block
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void drawPolgyon()
{

}