#include "shell.h"

/**
*first funtion that adds a node
*and return the size of list
*/

t_lst *nodeAdd(t_lst **lst, const char *data, int value) {
    if (!lst) {
        return NULL;
    }

    t_lst *new_node = malloc(sizeof(t_lst));
    if (!new_node) {
        return NULL;
    }

   _memset(new_node, 0, sizeof(t_lst));
    new_node->num = value;

    if (data) {
        new_node->str = _strdup(data);
        if (!new_node->str) {
            free(new_node);
            return NULL;
        }
    }

    new_node->next = *lst;
    *lst = new_node;
    return new_node;
}
/**
*second function that add the end node
*it returns the list of idex
*/

t_lst *endNode_add(list_t **data, const char *str, int number) {
    t_lst *newstmNode, *customNodePtr;

    if (!data)
        return NULL;

    customNodePtr = *data;
    newstmNode = (t_lst *)malloc(sizeof(t_lst));
    if (!newstmNode)
        return NULL;

    _memset((void *)newstmNode, 0, sizeof(t_lst));
    newstmNode->customData = number;

    if (str) {
        newstmNode->customStr = _strdup(str);
        if (!newstmNode->customStr) {
            free(newstmNode);
            return NULL;
        }
    }

    if (customNodePtr) {
        while (customNodePtr->nextNode)
            customNodePtr = customNodePtr->nextNode;
        customNodePtr->nextNode = newstmNode;
    } else {
        *head = (t_lst *)newstmNode;
    }

    return (t_lst *)newstmNode;
}

/**
*third funtion that add
*it returns size of list
*/

size_t strlsPrint(const t_lst *hd) {
    size_t counting = 0;

    while (hd) {
        _puts(hd->str ? hd->str : "(nil)");
        _puts("\n");
        hd = hd->next;
        counting++;
    }

    return counting;
}
/**
*third function
*/

int nodedel_index(list_t **data, unsigned int post)
{
    list_t *cur, *previous;
    unsigned int cnt = 0;

    if (!data || !*data)
        return 0;

    cur = *data;

    if (post == 0)
    {
        *data = cur->next;
        free(cur->str);
        free(cur);
        return 1;
    }

    while (cur)
    {
        if (cnt == post)
        {
            previous->next = cur->next;
            free(cur->str);
            free(cur);
            return 1;
        }
        cnt++;
        previous = cur;
        cur = cur->next;
    }

    return 0;
}
/**
forth functions 
*/

void lsFreet(t_lst **begin)
{
    t_lst *cur, *nextNode, *head;

    if (!begin || !*begin){
        return;
    }

    head = *begin;
    cur = head;
	/*to check if node is empty or not*/

    while (cur)
    {
        nextNode = cur->next;
        free(cur->str);
        free(cur);
        cur = nextNode;
    }

    *begin = NULL;
}
