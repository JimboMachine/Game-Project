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
		char * getStageName(int stage);					//���o�����d�W��
	private:
		char * stageBackGround[3] = { ".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp",".\\bitmaps\\�I��\\��a.bmp" };//�����d�I����
		string stageRivalBase[3] = { "Taiwan Base","Hong Kong Base","Thailand Base" };		//�����d�Ĥ誺��
		char * stageMusic[3] = { "sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3","sounds\\InvadingJapan!.mp3" };//�����d�I������
		char * stageName[3] = { ".\\bitmaps\\���d�W��\\�x�W.bmp", ".\\bitmaps\\���d�W��\\����.bmp", ".\\bitmaps\\���d�W��\\����.bmp" };
	};
}