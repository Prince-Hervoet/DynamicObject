#include <string>
#include <map>

namespace etools
{

    union ContentUnion
    {
        short value_short;
        int value_int;
        float value_float;
        double value_double;
        long value_long;
        long long value_longlong;
        unsigned int value_uint;
        char value_char;
        bool value_bool;
        void *ptrValue;
    };

    class DynamicNode
    {
        friend class DynamicObject;

    public:
        std::string Key() const
        {
            return key;
        }

        void *GetPtrValue() const
        {
            return content.ptrValue;
        }

        short GetShortValue() const
        {
            return content.value_short;
        }

        int GetIntValue() const
        {
            return content.value_int;
        }

        float GetFloatValue() const
        {
            return content.value_float;
        }

        double GetDoubleValue() const
        {
            return content.value_double;
        }

        long GetLongValue() const
        {
            return content.value_long;
        }

        long long GetLongLongValue() const
        {
            return content.value_longlong;
        }

        unsigned int GetUnsignedIntValue() const
        {
            return content.value_uint;
        }

        char GetCharValue() const
        {
            return content.value_char;
        }

        bool GetBoolValue() const
        {
            return content.value_bool;
        }

        bool IsBaseType()
        {
            return isBaseType;
        }

    private:
        bool isBaseType = true;
        std::string key;
        ContentUnion content;
        DynamicNode *next;
        DynamicNode *prev;
    };

    class DynamicObject
    {
    private:
        DynamicNode *head = nullptr;
        DynamicNode *tail = nullptr;
        std::map<std::string, DynamicNode *> *keyToMap = nullptr;
        DynamicNode *createNode(std::string &key);
        DynamicNode *createNode();
        void insertNode(DynamicNode *node);
        int size = 0;
        int flag = -1;
        DynamicNode *flagNode = nullptr;

    public:
        DynamicObject();
        DynamicObject(bool needMap);

        void Clear();
        void Set(std::string &key, bool value);
        void Set(std::string &key, char value);
        void Set(std::string &key, short value);
        void Set(std::string &key, int value);
        void Set(std::string &key, float value);
        void Set(std::string &key, double value);
        void Set(std::string &key, unsigned int value);
        void Set(std::string &key, long value);
        void Set(std::string &key, long long value);
        void Set(std::string &key, void *value);
        void Set(std::string &key, const char *value);

        void Add(bool value);
        void Add(char value);
        void Add(short value);
        void Add(int value);
        void Add(float value);
        void Add(double value);
        void Add(unsigned int value);
        void Add(long value);
        void Add(long long value);
        void Add(const char *value);
        void Add(void *value);
        DynamicNode *Get(std::string &key);
        DynamicNode *Get(int index);
        void Remove(std::string &key);
        void Remove(int index);
        DynamicNode *Next();
        bool HasNext();
        void ResetNext();
        DynamicNode *operator[](int index);

        int Size()
        {
            return size;
        }
    };

    DynamicObject &getDynamicObject(bool needMap);
};
