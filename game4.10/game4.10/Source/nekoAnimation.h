namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ߫}�ʵe
	/////////////////////////////////////////////////////////////////////////////

	class nekoAnimation 
	{
	public:
		nekoAnimation();
		void LoadBitmap();						//Ū���Ϥ�
		void OnMove();							//�ʵe�}�l����
		void OnShow();							//�N�ʵe��ܦb�e��
		int  GetX1();							//���o�Ϥ�X(��)�y��
		int  GetX2();							//���o�Ϥ�X(�k)�y��
		int  GetY();							//���o�Ϥ�Y�y��
		void SetCoordinate(int NewX,int NewY);	//�]�w�Ϥ��y��
		void MoveForward(rivalAnimation rival);	//�V�e����
	private:
		CAnimation	image;		// �߫}�ʵe����
		int x1, y;				// X(��),Y�y��
		int x2;					// X(�k)	
	};
}