Node* searchNode(string name) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}