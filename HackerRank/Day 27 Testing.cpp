class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        // complete this function
        vector<int> v;
        return v;
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        vector<int> v;
        for(int i = 1; i <= 100 ; i++)
            v.push_back(i);
        return v;
    }

    static int get_expected_result() {
        // complete this function
        
        return 0;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        vector<int> v;
        for(int i = 1; i <= 100 ; i++)
            v.push_back(i);
        v.push_back(1);
        return v;
    }

    static int get_expected_result() {
        // complete this function
        return 0;
    }

};