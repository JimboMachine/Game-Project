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
		int  GetX();							//���o�Ϥ�X�y��
		int  GetY();							//���o�Ϥ�Y�y��
		void SetCoordinate(int NewX,int NewY);	//�]�w�Ϥ��y��
		void MoveForward();						//�V�e����
	private:
		CAnimation	image;		// �߫}�ʵe����
		int x, y;				// X,Y�y��
	};
}