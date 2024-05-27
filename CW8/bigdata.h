#define BIGDATA+H

#include <vector>

class BigData{
    private:
        int id;
        std::vector<int> *vec
    public:
        BigData(int _id);
        BigData(const BigData &src);
        BigData& operator =(const BigData &src);
        ~BigData();
};

#endif