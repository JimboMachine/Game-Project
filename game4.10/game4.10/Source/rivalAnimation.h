namespace game_framework{
	
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѼĤH�ʵe
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation;						//�����sĶ�����D����|��nekoAnimation���s�b����A��include
	
	class rivalAnimation 
	{
	public:
		rivalAnimation();
		void LoadBitmap();						//Ū���Ϥ�
		void OnMove();							//�ʵe�}�l����
		void OnShow();							//�N�ʵe��ܦb�e��
		int  GetX1();							//���o�Ϥ�X�y��
		int  GetX2();							//���o�Ϥ�X(�k)�y��
		int  GetY();							//���o�Ϥ�Y�y��
		void SetCoordinate(int NewX, int NewY);	//�]�w�Ϥ��y��
		void MoveForward(nekoAnimation *neko);	//�V�e����
		bool GetIsAlive();							//���o�O�_�٬���
		int	 GetAttack();						//���o�����O
		int	 GetHealth();						//���o��O
		void SetHealth(int NewHealth);					//�����O��
		
	private:
		CAnimation	image;		// ���J�ʵe����
		int x1, y;				// X,Y�y��
		int x2;					// X(�k)
		bool IsAlive;			// �O�_����
		int range;				// ����i�������d��
		int health;				//����ͩR��
		int attack;				//��������O
		int attackDelay;		//��������W�v
		int delay;				//�h�p��ثe�w�gDelay�F�X��
		void die();				//�P�_��O�p�󵥩�s�A���߫h���榹���
	};
}