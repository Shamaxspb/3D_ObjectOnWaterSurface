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

const int START_WINDOW_WIDTH = 1366;
const int START_WINDOW_HEIGHT = 768;

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

<<<<<<< ActualToMerge

	// CREATE VERTICES VECTOR ===============================================================================
	// variables to fill verticesContainer
	vector<float> verticesContainer;	// vector with all vertices
	float x = 0;
	float& x1 = x, & x2 = x;
	float y1 = 16, y2 = y1 - 12;
	float z = 0;
	float& z1 = z, & z2 = z;
	fstream waveFile;

	waveFile.open("WaveHeight.txt", fstream::in);
	if (!waveFile.is_open())
	{
		cout << "ERROR\tcouldn't open WaveHeight.txt" << endl;
		return -1;
	}

	while (!waveFile.eof())
	{
		waveFile >> z;

		verticesContainer.push_back(x1);	// x1
		verticesContainer.push_back(y1);	// y1
		verticesContainer.push_back(z1);	// z1

		verticesContainer.push_back(x2);	// x2
		verticesContainer.push_back(y2);	// y2
		verticesContainer.push_back(z2);	// z2

		x += 6;
	}

	PrintVector(verticesContainer);

	// ==============================================================================

>>>>>>> master
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

	Shader myShader("myVertexShader.vs", "myFragmentShader.fs");

	//float testSquareVertices[] = {
	//	// position			// color			// indicies of vertices
	//	-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,	// A - 0
	//	-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	// B - 1
	//	 0.0f,  0.5f, 0.0f,	0.0f, 0.0f, 1.0f,	// C - 2
	//	 0.0f, -0.5f, 0.0f,	1.0f, 1.0f, 0.0f,	// D - 3
	//	 0.5f,  0.5f, 0.0f,	0.0f, 1.0f, 1.0f,	// E - 4
	//	 0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 1.0f	// F - 5
	//};

	float testSquareVertices[] = {
		// position			// indicies of vertices
		-0.5f,  0.5f, 0.0f,	// A - 0 
		-0.5f, -0.5f, 0.0f,	// B - 1
		 0.0f,  0.5f, 0.0f, // C - 2
		 0.0f, -0.5f, 0.0f,	// D - 3
		 0.5f,  0.5f, 0.0f, // E - 4
		 0.5f, -0.5f, 0.0f	// F - 5
	};

	unsigned int testSquareIndicies[] = {
		0, 1, 3,	// triangle ABD
		0, 3, 2,	// triangle ADC
		2, 3, 5,	// triangle CDF
		2, 5, 4		// triangle CFE
	};

	float test2SquareVertices[] = {
		// position			// indicies of vertices
		-1.0f,  0.6f, 0.0f,	// A - 0 
		-1.0f, -0.6f, 0.0f,	// B - 1
		-0.8f,  0.6f, 0.0f,	// C - 2
		-0.8f, -0.6f, 0.0f,	// D - 3
		-0.6f,  0.6f, 0.0f,	// E - 4
		-0.6f, -0.6f, 0.0f,	// F - 5
		-0.4f,  0.6f, 0.0f,	// G - 6
		-0.4f, -0.6f, 0.0f,	// H - 7
		-0.2f,  0.6f, 0.0f,	// I - 8
		-0.2f, -0.6f, 0.0f,	// J - 9
		 0.0f,  0.6f, 0.0f,	// K - 10
		 0.0f, -0.6f, 0.0f,	// L - 11
		 0.2f,  0.6f, 0.0f,	// M - 12
		 0.2f, -0.6f, 0.0f,	// N - 13
		 0.4f,  0.6f, 0.0f,	// O - 14
		 0.4f, -0.6f, 0.0f,	// P - 15
		 0.6f,  0.6f, 0.0f,	// Q - 16
		 0.6f, -0.6f, 0.0f,	// R - 17
		 0.8f,  0.6f, 0.0f,	// S - 18
		 0.8f, -0.6f, 0.0f,	// T - 19
		 1.0f,  0.6f, 0.0f,	// U - 20
		 1.0f, -0.6f, 0.0f,	// V - 21
	};

	unsigned int test2SquareIndicies[] = {
		0, 1, 3,	// triangle ABD
		0, 3, 2,	// triangle ADC
		2, 3, 5,	// triangle CDF
		2, 5, 4,	// triangle CFE
		4, 5, 7,	// triangle EFH
		4, 7, 6,	// triangle EHG
		6, 7, 9,	// triangle GHJ
		6, 9, 8,	// triangle GJI
		8, 9, 11,	// triangle IJL
		8, 11, 10,	// triangle ILK
		10, 11, 13,	// triangle KLN
		10, 13, 12,	// triangle KNM
		12, 13, 15,	// triangle MNP
		12, 15, 14,	// triangle MPO
		14, 15, 17,	// triangle OPR
		14, 17, 16,	// triangle ORQ
		16, 17, 19,	// triangle QRT
		16, 19, 18,	// triangle QTS
		18, 19, 21,	// triangle STV
		18, 21, 20	// triangle SVU
	};
	
	unsigned int VAO, VBO, EBO;

	// create and bind VAO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	 //allocate memory in GPU and copy there data from testSquareVertices array
	glBufferData(GL_ARRAY_BUFFER, sizeof(test2SquareVertices), test2SquareVertices, GL_STATIC_DRAW);

	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// allocate memory in GPU and copy there data from testSquareIndicies array
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(test2SquareIndicies), test2SquareIndicies, GL_STATIC_DRAW);

	// finding attribs
	/*unsigned int posAttrib = glGetAttribLocation(static Shader::ID, "vertexPosition");
	unsigned int colAttrib = glGetAttribLocation(Shader::ID, "vertexColor");*/


	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);*/
	
	
	// uncomment this call to draw in wireframe polygons.
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//myShader.Use();

	// render loop ==========================================================================================
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		glClearColor(0.63f, 0.46f, 0.84f, 1.0f);
		//glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// render
		myShader.Use();
		glBindVertexArray(VAO);
		//glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0); // for 4 triangles
		glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_INT, 0); // for 4 triangles
		glBindVertexArray(0);

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
