#include <iostream>

int rect_contained(int w, int h)
{
    int sw,sh;

    int sum = 0;

    for (sw = 1; sw <= w; sw++)
    {
        for (sh = 1; sh <= h; sh++)
        {
            sum += (h - (sh - 1)) * (w - (sw - 1));
        }
    }

    return sum;
}

int main(void)
{
    int x,y;
    int closest_delta = 50000;
    int area = 0;
    int sum;

    for (x = 1; x<10000; x++)
    {
        for (y = 1; y <= x; y++)
        {
            sum = rect_contained(x,y);
            if (abs(sum  - 2000000) < closest_delta)
            {
                closest_delta = abs(sum - 2000000);
                area = x*y;
            }
        }
    }

    std::cout << closest_delta << " " << area << std::endl;
}
