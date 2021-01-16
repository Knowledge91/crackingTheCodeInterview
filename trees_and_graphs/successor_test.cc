#include "successor.h"

#include "gtest/gtest.h"

// TEST(successor, example1) {
//   // see
//   //
//   https://en.wikipedia.org/wiki/Binary_search_tree#/media/File:Binary_search_tree.svg
//   Node *n1 = new Node(1);
//   Node *n3 = new Node(3);
//   Node *n4 = new Node(4);
//   Node *n6 = new Node(6);
//   Node *n7 = new Node(7);
//   Node *n8 = new Node(8);
//   Node *n10 = new Node(10);
//   Node *n13 = new Node(13);
//   Node *n14 = new Node(14);

//   n8->left = n3;
//   n8->right = n10;
//   n3->left = n1;
//   n3->right = n6;
//   n6->left = n4;
//   n6->right = n7;
//   n8->right = n10;
//   n10->right = n14;
//   n14->left = n13;
//   n3->parent = n8;
//   n1->parent = n3;
//   n6->parent = n3;
//   n4->parent = n6;
//   n7->parent = n6;
//   n10->parent = n8;
//   n14->parent = n10;
//   n13->parent = n14;

//   EXPECT_EQ(successor(n7)->value, n8->value);
// }

// TEST(successor, example2) {
//   // see
//   //
//   https://en.wikipedia.org/wiki/Binary_search_tree#/media/File:Binary_search_tree.svg
//   Node *n1 = new Node(1);
//   Node *n3 = new Node(3);
//   Node *n4 = new Node(4);
//   Node *n6 = new Node(6);
//   Node *n7 = new Node(7);
//   Node *n8 = new Node(8);
//   Node *n10 = new Node(10);
//   Node *n13 = new Node(13);
//   Node *n14 = new Node(14);

//   n8->left = n3;
//   n8->right = n10;
//   n3->left = n1;
//   n3->right = n6;
//   n6->left = n4;
//   n6->right = n7;
//   n8->right = n10;
//   n10->right = n14;
//   n14->left = n13;
//   n3->parent = n8;
//   n1->parent = n3;
//   n6->parent = n3;
//   n4->parent = n6;
//   n7->parent = n6;
//   n10->parent = n8;
//   n14->parent = n10;
//   n13->parent = n14;

//   EXPECT_EQ(successor(n3)->value, n4->value);
// }