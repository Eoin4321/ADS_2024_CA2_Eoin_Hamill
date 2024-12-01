#include "pch.h"
#include "CppUnitTest.h"
#include "../CA2EoinHamill/KeyValuePair.h"
#include "../CA2EoinHamill/BinaryTree.h"
#include "../CA2EoinHamill/BSTNode.h"
#include "../CA2EoinHamill/Tree.h"
//Everything in this namespace includes all the stuff I need for Unit Testing
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MethodsTest
{
	TEST_CLASS(MethodsTest)
	{
	public:

		//Testing The Put Method
		TEST_METHOD(TestingPutMethod)
		{
			//Making the tree for testing and adding in values
			Tree<int, string> tree;
			tree.put(1, "num1");
			tree.put(2, "num2");
			tree.put(3, "num3");
			tree.put(4, "num4");
			tree.put(5, "num5");
			
			Assert::AreEqual(string("num1"), tree.get(1));
		}


		//Testing The Clear Method
		TEST_METHOD(TestingClearMethod)
		{
		//Making the tree for testing and adding in values
			Tree<int, string> tree;
			tree.put(1, "num1");
			tree.put(2, "num2");
			tree.put(3, "num3");
			tree.put(4, "num4");
			tree.put(5, "num5");
			//Empty Tree to compare with
			Tree<int, string> tree2;
			tree.clear();
			Assert::AreEqual(tree.size(), 0);
			
		}

		//Testing The Get Method
		TEST_METHOD(TestingGetMethod)
		{
			//Making the tree for testing and adding in values
			Tree<int, string> tree;
			tree.put(1, "num1");
			tree.put(2, "num2");
			tree.put(3, "num3");
			tree.put(4, "num4");
			tree.put(5, "num5");
			//Values to compare with
			string comparasion = "num5";
			string original = tree.get(5);

			//Checking if they are equal
			Assert::AreEqual(comparasion, original, L"Values dont match");
		}

		//Testing The Contains Method
		TEST_METHOD(TestingContainsMethod)
		{
			//Making the tree for testing and adding in values
			Tree<int, string> tree;
			tree.put(1, "num1");
			tree.put(2, "num2");
			tree.put(3, "num3");
			tree.put(4, "num4");
			tree.put(5, "num5");

			//Checking if it contains 
			Assert::IsTrue(tree.containsKey(3));
			Assert::IsFalse(tree.containsKey(56));
		}

		//Testing The Remove Method
		TEST_METHOD(TestingRemoveMethod)
		{
			//Making the tree for testing and adding in values
			Tree<int, string> tree;
			tree.put(1, "num1");
			tree.put(2, "num2");
			tree.put(3, "num3");
			tree.put(4, "num4");
			tree.put(5, "num5");

			tree.removeKey(3);
			//Checking if it has been removed. 
			Assert::IsFalse(tree.containsKey(3));
			Assert::IsTrue(tree.containsKey(5));
		}
	};


}
