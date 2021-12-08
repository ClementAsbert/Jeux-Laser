#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include<vector>
#include<memory>

class image;
class transformation{
public:
    virtual ~transformation() =default;
    virtual void transform(image& img)const = 0;
};
class transformationFlou : public transformation{
public:
    virtual void transform(image& img)const override;
};

class transformationNegatif: public transformation{
public:
    virtual void transform(image& img)const override;
};

class transformationIdentite : public transformation
{
public:
    virtual void transform(image& img)const override;
};

class transformationComposee : public transformation
{
public:
    transformationComposee();
    void ajoute(std::unique_ptr<transformation> tr);
    virtual void transform(image& img)const override;
private:
    std::vector<std::unique_ptr<transformation>> d_transformation;
};


#endif TRANSFORMATION_H
