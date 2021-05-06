

using namespace std;

class Grid
{   
    public:
        Grid();
        int GRIDWIDTH;
        int GRIDHEIGHT;

        int *gridArray;
        void setFilled(int, int);
        void setUnFilled(int, int);
        void printFilled();
        bool checkEmpty(int, int);



};