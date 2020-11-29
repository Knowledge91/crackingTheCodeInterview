struct DMNode {
  DMNode(int val) : val(val) { next = nullptr; };
  int val;
  DMNode *next;
};

void deleteMiddleNode(DMNode *node) {
  DMNode *next_node = node->next;
  *node = *next_node;
  delete next_node;
}