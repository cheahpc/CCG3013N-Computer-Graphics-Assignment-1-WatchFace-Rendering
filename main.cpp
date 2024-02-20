#include "init.cpp"

using namespace std;

int main()
{
	// Initialize the windows
	init();

	// Render the scene
	glutDisplayFunc(renderMaster);

	glutMainLoop();
	system("PAUSE");
	return 0;
}