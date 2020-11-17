#include "D3DUtil.h"

//constructor
DPhoenix::Camera::Camera()
{
	//create default perspective matrix
	//position at +10 on Z
	mPosition = XMFLOAT3(0.0f, 0.0f, 10.0f);
	//Up direction is Y
	mUpDir = XMFLOAT3(0.0f, 1.0f, 0.0f);
	//aspect ratio (should be updated on resize)
	float ratio = 1440 / 900;
	//Send FOV, asepct ratio, nearplane, farplane
	SetPerspective(XM_PI / 4.0f, ratio, 1.0f, 10000.0f);
	//default target looking right
	mTarget.x = 1.0f; mTarget.y = 0.0f; mTarget.z = 0.0f;
	//create default view matrix
	Update(mTarget);
}

//default destructor
DPhoenix::Camera::~Camera()
{
}

void DPhoenix::Camera::SetPerspective(float FOV, float aspectRatio, 
	float nearRange, float farRange)
{
	//set vars
	mFOV = FOV;
	mAspectRatio = aspectRatio;
	mNearRange = nearRange;
	mFarRange = farRange;

	//set the camera's perspecive matrix (projection)
	mMatrixProj = XMMatrixPerspectiveFovLH(mFOV, mAspectRatio, 
		mNearRange, mFarRange);
}

//Update
void DPhoenix::Camera::Update(XMFLOAT3 lookDirection)
{
	//This updates the camera target based on look direction
	mTarget.x = mPosition.x + lookDirection.x;
	mTarget.y = mPosition.y + lookDirection.y;
	mTarget.z = mPosition.z + lookDirection.z;

	//Build the view matrix (position, target, up direction)
	XMVECTOR pos = XMVectorSet(mPosition.x, mPosition.y, mPosition.z, 1.0f);
	XMVECTOR target = XMVectorSet(mTarget.x, mTarget.y, mTarget.z, 1.0f);
	XMVECTOR up = XMVectorSet(mUpDir.x, mUpDir.y, mUpDir.z, 0.0f);

	//create view matrix
	mMatrixView = XMMatrixLookAtLH(pos, target, up);
}

//adjust rotation relative to current rotation values 
void DPhoenix::Camera::Rotate(float x, float y, float z)
{
	mRotation.x += x; mRotation.y += y; mRotation.z += z;
}

//set target valuesrelative to current
void DPhoenix::Camera::Look(float x, float y, float z)
{
	mPosition.x += x; mPosition.y += y; mPosition.z += z;
}

//move relative position and target
void DPhoenix::Camera::Move(float x, float y, float z)
{
	mPosition.x += x; mPosition.y += y; mPosition.z += z;
	mTarget.x += x; mTarget.y += y; mTarget.z += z;
}
