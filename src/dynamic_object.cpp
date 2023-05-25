#include "dynamic_object.hpp"
using namespace etools;

DynamicObject &etools::getDynamicObject(bool needMap)
{
    return *(new DynamicObject());
}

DynamicObject::DynamicObject(bool needMap)
{
    if (needMap)
    {
        this->keyToMap = new std::map<std::string, DynamicNode *>;
    }
}

DynamicObject::DynamicObject()
{
    this->keyToMap = new std::map<std::string, DynamicNode *>;
}

void DynamicObject::Clear()
{
    if (size == 0)
    {
        return;
    }
    DynamicNode *run = head;
    while (run)
    {
        DynamicNode *temp = run->next;
        delete run;
        run = temp;
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
    if (keyToMap != nullptr)
    {
        keyToMap->clear();
    }
}

void DynamicObject::Set(std::string &key, short value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, char value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, unsigned int value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, int value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, float value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_float = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, double value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_double = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, long value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, long long value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = true;
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, void *value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = false;
    node->content.ptrValue = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, bool value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = false;
    node->content.value_bool = value;
    insertNode(node);
}

void DynamicObject::Set(std::string &key, const char *value)
{
    DynamicNode *node = createNode(key);
    node->isBaseType = false;
    node->content.ptrValue = (void *)value;
    insertNode(node);
}

void DynamicObject::Add(const char *value)
{
    DynamicNode *node = createNode();
    node->content.ptrValue = (void *)value;
    insertNode(node);
}

void DynamicObject::Add(short value)
{
    DynamicNode *node = createNode();
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Add(int value)
{
    DynamicNode *node = createNode();
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Add(unsigned int value)
{
    DynamicNode *node = createNode();
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Add(long value)
{
    DynamicNode *node = createNode();
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Add(long long value)
{
    DynamicNode *node = createNode();
    node->content.value_longlong = value;
    insertNode(node);
}

void DynamicObject::Add(float value)
{
    DynamicNode *node = createNode();
    node->content.value_float = value;
    insertNode(node);
}

void DynamicObject::Add(double value)
{
    DynamicNode *node = createNode();
    node->content.value_double = value;
    insertNode(node);
}

void DynamicObject::Add(bool value)
{
    DynamicNode *node = createNode();
    node->content.value_bool = value;
    insertNode(node);
}

void DynamicObject::Add(void *value)
{
    DynamicNode *node = createNode();
    node->content.ptrValue = value;
    insertNode(node);
}

void DynamicObject::Add(char value)
{
    DynamicNode *node = createNode();
    node->content.value_char = value;
    insertNode(node);
}

DynamicNode *DynamicObject::Get(std::string &key)
{
    if (!keyToMap)
    {
        return nullptr;
    }
    auto it = keyToMap->find(key);
    if (it != keyToMap->end())
    {
        return it->second;
    }
    return nullptr;
}

DynamicNode *DynamicObject::Get(int index)
{
    if (size == 0 || index < 0 || index >= size)
    {
        return nullptr;
    }
    int mid = 0, count = 0;
    if ((index & 1) == 0)
    {
        mid = (index >> 1) - 1;
    }
    else
    {
        mid = ((index - 1) >> 1);
    }
    DynamicNode *run = nullptr;
    if (index <= mid)
    {
        run = head;
        while (run)
        {
            if (count == index)
            {
                return run;
            }
            run = run->next;
            count += 1;
        }
    }
    else
    {
        count = size - 1;
        run = tail;
        while (run)
        {
            if (count == index)
            {
                return run;
            }
            run = run->prev;
            count -= 1;
        }
    }
}

void DynamicObject::Remove(std::string &key)
{
    if (!keyToMap || size == 0)
    {
        return;
    }
    auto it = keyToMap->find(key);
    if (it == keyToMap->end())
    {
        return;
    }
    DynamicNode *target = it->second;
    if (target == head)
    {
        DynamicNode *temp = head->next;
        delete head;
        head = temp;
        if (temp)
        {
            temp->prev = nullptr;
        }
        if (!head)
        {
            tail = head;
        }
    }
    else if (target == tail)
    {
        DynamicNode *temp = tail->prev;
        delete tail;
        tail = temp;
        if (temp)
        {
            temp->next = nullptr;
        }
        if (!tail)
        {
            head = tail;
        }
    }
    else
    {
        DynamicNode *p1 = target->prev;
        DynamicNode *p2 = target->next;
        p1->next = p2;
        p2->prev = p1;
    }
    keyToMap->erase(key);
    delete target;
    size -= 1;
}

void DynamicObject::Remove(int index)
{
    DynamicNode *target = this->Get(index);
    if (!target)
    {
        return;
    }
    if (target == head)
    {
        DynamicNode *temp = head->next;
        head = temp;
        if (temp)
        {
            temp->prev = nullptr;
        }
        if (!head)
        {
            tail = head;
        }
    }
    else if (target == tail)
    {
        DynamicNode *temp = tail->prev;
        tail = temp;
        if (temp)
        {
            temp->next = nullptr;
        }
        if (!tail)
        {
            head = tail;
        }
    }
    else
    {
        DynamicNode *p1 = target->prev;
        DynamicNode *p2 = target->next;
        p1->next = p2;
        p2->prev = p1;
    }
    keyToMap->erase(target->key);
    delete target;
    size -= 1;
}

DynamicNode *DynamicObject::createNode(std::string &key)
{
    auto it = keyToMap->find(key);
    if (it != keyToMap->end())
    {
        return it->second;
    }
    DynamicNode *node = new DynamicNode();
    node->key = key;
    return node;
}

DynamicNode *DynamicObject::createNode()
{
    DynamicNode *node = new DynamicNode();
    return node;
}

void DynamicObject::insertNode(DynamicNode *node)
{
    if (!node)
    {
        return;
    }
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    keyToMap->insert(std::make_pair(node->key, node));
    size += 1;
}

DynamicNode *DynamicObject::Next()
{
    if (!HasNext())
    {
        return nullptr;
    }
    if (flag == -1)
    {
        flag = 1;
        flagNode = head;
        return head;
    }
    flagNode = flagNode->next;
    flag += 1;
    return flagNode;
}

bool DynamicObject::HasNext()
{
    if (size == 0)
    {
        return false;
    }
    return flag < size;
}

void DynamicObject::ResetNext()
{
    flag = -1;
    flagNode = nullptr;
}

DynamicNode *DynamicObject::operator[](int index)
{
    return Get(index);
}