namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class������ܨ�����s����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoButton {
	public:
		nekoButton();
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��
		void SetIsClicked(int buttonNum,bool clicked);//�]�w�O�_�Q���U
		void SetClicked(int pointX,int pointY);				//�]�w���U�ɪ��ʧ@
		bool checkNowClicked(int nekoNumber);				//�^�ǲ{�b�O���O���U�h����������
	private:
		static CMovingBitmap button[20];		//���s�ϧ�
		int xGap;						//���s�P���s������X���Z
		int yGap;						//���s�P���s������Y���Z
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
		bool isClicked[10];				//���s�O�_�Q���U
		int x[10];						//���sx�y��
		int y[10];						//���sy�y��
		int buttonDelay[10];			//���s���N�o�ɶ�
		int delay[10];					//���s�ثe����ɶ�
	};
}