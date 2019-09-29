class Student :  public Person{
	private:
		vector<int> testScores; 
        int sum,result;
	public:
  		Student(string first,string last,int id,vector<int> scores) : Person(first,last,id)
            {
                testScores = scores;
                sum = 0;
                for(int i=0;i<testScores.size();i++)
                    sum += testScores[i];
                result = sum/testScores.size();
        }
  
  		char calculate()
            {
            if(result>=90)
                return 'O';
            else if(result>=80)
                return 'E';
            else if(result>=70)
                return 'A';
            else if(result>=55)
                return 'P';
            else if(result>= 40)
                return 'D';
            else
                return 'T';
            
        }
};