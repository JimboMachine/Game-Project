namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class�������d��T����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageImformation {
	public:
		stageImformation();
		char*  getStageBackground(int stage);		//���o�����d�I����
		string getRivalBase(int stage);				//���o�����d�Ĥ誺��
		char * getMusic(int stage);					//���o�����d�I������
		char * getStageName(int stage);				//���o�����d�W��
		void   LoadBitmap();						//Ū���Ϥ�
		void   ShowBitmapBackGround(int stage);		//��ܭI���Ϥ�
		void   ShowBitmapName(int stage);			//������d�W�ٹϤ�
	private:
		static CMovingBitmap BackGround[7];			//�I��
		static CMovingBitmap Name[7];				//���d�W��
		char * stageBackGround[7] = { ".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp" };//�����d�I����
		string stageRivalBase[7] = { "Taiwan Base","Hong Kong Base","Thailand Base","China Base","Mongolia Base","Korea Base","Japan Base"};//�����d�Ĥ誺��
		char * stageMusic[3] = { "sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3" };//�����d�I������
		char * stageName[7] = { ".\\bitmaps\\���d�W��\\�x�W.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�X�j.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\�饻.bmp" };//���d�W��
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
	};
}