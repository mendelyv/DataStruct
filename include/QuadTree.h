#ifndef M_QUADTREE_H
#define M_QUADTREE_H

#include <string>

class QuadTreeRect
{
public:
    int x;
    int y;
    int width;
    int height;

public:
    QuadTreeRect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
    bool Contains(QuadTreeRect* target)
    {
        return (target->x >= this->x && target->x + target->width <= this->x + this->width && target->y >= this->y && target->y + target->height <= this->y + this->height);
    }
};

typedef struct
{
    std::string name;
    int age;
    int gender;
    QuadTreeRect* rect;
} QuadTestEntity;

template <typename T>
class QuadTree
{
public:
    QuadTree<T>* children[4];
    QuadTreeRect* rect;
    bool divided;

    int objectCount;
    int depth;
    int MAX_COUNT;
    int MAX_DEPTH;

    T* objects[10];

public:
    QuadTree<T>(QuadTreeRect* rect)
    {
        this->MAX_DEPTH = 5;
        this->MAX_COUNT = 10;
        this->rect = rect;
        this->objectCount = 0;
        this->depth = 0;
        this->divided = false;
        for (int i = 0; i < 4; i++)
            this->children[i] = nullptr;
        for (int i = 0; i < 10; i++)
            this->objects[i] = nullptr;
    }
    ~QuadTree<T>()
    {
        for (int i = 0; i < 4; i++)
            if (nullptr != this->children[i])
            {
                delete this->children[i];
                this->children[i] = nullptr;
            }
        for (int i = 0; i < 10; i++)
            if (nullptr != this->objects[i])
            {
                delete this->objects[i];
                this->objects[i] = nullptr;
            }
        this->rect = nullptr;
    }

    bool Insert(T* object)
    {
        if (!this->rect->Contains(object->rect))
        {
            // printf(" ***** insert object is not in rect ***** \n");
            // printf(" x: %d, y: %d, width: %d, height: %d \n", object->rect->x, object->rect->y, object->rect->width, object->rect->height);
            // printf(" this x: %d, y: %d, width: %d, height: %d \n\n", this->rect->x, this->rect->y, this->rect->width, this->rect->height);
            return false;
        }

        if (this->objectCount < this->MAX_COUNT)
        {
            this->objects[this->objectCount] = object;
            this->objectCount++;
            return true;
        }

        if (this->depth > this->MAX_DEPTH)
        {
            printf(" ***** max depth and max count, check it ***** \n");
            return false;
        }

        if (!this->divided)
        {
            this->divide();
            this->divided = true;
            this->depth++;
        }
        for (int i = 0; i < 4; i++)
        {
            QuadTree<T>* child = this->children[i];
            if (child->Insert(object))
                return true;
        }

        return false;
    }

    void divide()
    {
        int x = this->rect->x;
        int y = this->rect->y;
        int w = this->rect->width;
        int h = this->rect->height;

        this->children[0] = new QuadTree<T>(new QuadTreeRect(x + w / 2, y, w / 2, h / 2));
        this->children[1] = new QuadTree<T>(new QuadTreeRect(x, y, w / 2, h / 2));
        this->children[2] = new QuadTree<T>(new QuadTreeRect(x, y + h / 2, w / 2, h / 2));
        this->children[3] = new QuadTree<T>(new QuadTreeRect(x + w / 2, y + h / 2, w / 2, h / 2));
    }

    int Query(QuadTreeRect* range, T** found, int foundIndex)
    {
        // printf(" ===== Query rect ===== \n");
        // printf(" x: %d, y: %d, width: %d, height: %d \n", this->rect->x, this->rect->y, this->rect->width, this->rect->height);
        // printf(" ===== Query rect ===== \n");
        if (!this->rect->Contains(range))
        {
            // printf(" ----- range is not contains in rect ----- \n");
            // printf(" x: %d, y: %d, width: %d, height: %d \n\n", this->rect->x, this->rect->y, this->rect->width, this->rect->height);
            return 0;
        }
        if (this->objectCount > 0)
        {
            // printf(" ----- objectCount > 0 ----- \n");
            for (int i = 0; i < this->objectCount; i++)
            {
                T* obj = this->objects[i];
                if (nullptr == obj)
                    break;
                // if (obj->rect->Contains(range))
                if (range->Contains(obj->rect))
                {
                    // printf(" ----- found object ----- \n");
                    // printf(" name: %s, age: %d, gender: %d \n", obj->name.c_str(), obj->age, obj->gender);
                    found[foundIndex++] = obj;
                    // printf(" ----- foundIndex: %d ----- \n", foundIndex);
                }
            }
        }
        if (this->divided)
        {
            for (int i = 0; i < 4; i++)
            {
                QuadTree<T>* child = this->children[i];
                child->Query(range, found, foundIndex);
            }
        }
        return foundIndex;
    }
};

#endif
