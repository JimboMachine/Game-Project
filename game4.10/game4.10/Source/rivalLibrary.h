namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѼĤ��Ų�����Ĥ誺�U�����
	// 
	/////////////////////////////////////////////////////////////////////////////

	class rivalLibrary {
	public:
		//����򥻸��
		rivalLibrary(string name);
		int range;				//����i�������d��
		int health;				//����ͩR��
		int attack;				//��������O
		int attackDelay;		//��������W�v
		int walkAnimationStart;	//�Ĥ@�Ӧ樫�ʵe
		int walkAnimationEnd;	//�̫�@�Ӧ樫�ʵe
		int attackAnimationStart;//�Ĥ@�ӧ����ʵe
		int attackAnimationEnd;	//�̫�@�ӧ����ʵe
		int deathAnimationStart;//�Ĥ@�Ӧ��`�ʵe
		int deathAnimationEnd;	//�̫�@�Ӧ��`�ʵe
		int deathHeightChange;	//���h����Y�y�нվ�
		int moveSpeed;			//���Ⲿ�ʳt��
		char *imageList(string name, int);//�^�Ǩ���Ϥ�
		int imageQuantity;		//�Ϥ��ƶq



	};


}