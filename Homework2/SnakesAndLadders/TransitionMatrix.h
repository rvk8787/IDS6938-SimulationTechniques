int size = 0;  //TODO
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 0; //TODO

double prob = 0.0 ;  //TODO




void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO
	for (int i = 0; i < 101; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			TransitionMatrix(i, j+i) = 1.0/6.0;
		}
		
		
	}

	//std:: cout << TransitionMatrix;

}