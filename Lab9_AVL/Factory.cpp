
#include "Factory.h"
#include "avl.h"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getAVL()

	Creates and returns an object whose class extends BSTInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
AVLInterface * Factory::getAVL()
{
	return new avl();//Modify this line
}
