#pragma once
#include <stdio.h>
#include <stdlib.h> /* �üƬ������ */
#include <time.h>   /* �ɶ�������� */
#include <string.h>

//�ŧi�O�_�P�w�P���G
int Observe_Signpost_Count = 9;
int Observe_Sundial_Count = 9;
int Observe_Stranger_Plazza_Count = 9;

class roll {
public:
	int success; // �P�w���G(0: ����, 1: ���\, 2:�x�����\, 3:�������\)
	int rolling; // �Y�뵲�G
	// Check Category: �P�w�W��(EX:�[��P�w), Successful Rate: �P�w���\�v
	void check(int Successful_Rate) {
		// ���Ͷü� 
		srand(time(NULL));
		rolling = rand() % 100 + 1;

		// �T�{�P�w�O�_���\
		if (rolling > Successful_Rate) {
			success = 0;
		}
		else if (rolling <= Successful_Rate/5) {
			success = 3;
		}
		else if (rolling <= Successful_Rate / 2) {
			success = 2;
		}
		else {
			success = 1;
		}
	}
};