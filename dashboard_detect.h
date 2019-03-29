#ifndef DASHBOARD_DETECT_H
#define DASHBOARD_DETECT_H


class DashboardDetect
{
public:
    DashboardDetect();

//public:
//  DashboardDetect();

//  ~DashboardDetect();

//  int dashboardDetect(Mat src, std::vector<CPlate> &resultVec, int type,
//                  bool showDetectArea, int img_index = 0);

//  int plateDetect(Mat src, std::vector<CPlate> &resultVec, int img_index = 0);

//  void LoadSVM(std::string s);

//  inline void setPDLifemode(bool param) { m_plateLocate->setLifemode(param); }

//  inline void setPDDebug(bool param) {
//    m_plateLocate->setDebug(param);
//    setDetectShow(param);
//  }

//  inline bool getPDDebug() { return m_plateLocate->getDebug(); }

//  inline void setDetectType(int param) { m_type = param; }

//  inline void setGaussianBlurSize(int param) {
//    m_plateLocate->setGaussianBlurSize(param);
//  }

//  inline int getGaussianBlurSize() const {
//    return m_plateLocate->getGaussianBlurSize();
//  }

//  inline void setMorphSizeWidth(int param) {
//    m_plateLocate->setMorphSizeWidth(param);
//  }

//  inline int getMorphSizeWidth() const {
//    return m_plateLocate->getMorphSizeWidth();
//  }

//  inline void setMorphSizeHeight(int param) {
//    m_plateLocate->setMorphSizeHeight(param);
//  }

//  inline int getMorphSizeHeight() const {
//    return m_plateLocate->getMorphSizeHeight();
//  }

//  inline void setVerifyError(float param) {
//    m_plateLocate->setVerifyError(param);
//  }

//  inline float getVerifyError() const {
//    return m_plateLocate->getVerifyError();
//  }

//  inline void setVerifyAspect(float param) {
//    m_plateLocate->setVerifyAspect(param);
//  }

//  inline float getVerifyAspect() const {
//    return m_plateLocate->getVerifyAspect();
//  }

//  inline void setVerifyMin(int param) { m_plateLocate->setVerifyMin(param); }

//  inline void setVerifyMax(int param) { m_plateLocate->setVerifyMax(param); }

//  inline void setJudgeAngle(int param) { m_plateLocate->setJudgeAngle(param); }

//  inline void setMaxPlates(int param) { m_maxPlates = param; }

//  inline int getMaxPlates() const { return m_maxPlates; }

//  inline void setDetectShow(bool param) { m_showDetect = param; }
//  inline bool getDetectShow() const { return m_showDetect; }

// private:

//  int m_maxPlates;

//  //SceneMode m_mode;

//  CPlateLocate* m_plateLocate;

//  int m_type;

//  static std::string m_pathSvm;

//  // show the detect result image
//  bool m_showDetect;

};

#endif // DASHBOARD_DETECT_H
