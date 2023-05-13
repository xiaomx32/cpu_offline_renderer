#include <raytracing/core/transform.h>

// Matrix4x4 constructor
Matrix4x4::Matrix4x4() {
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.f;

    m[0][1] = m[0][2] = m[0][3] = m[1][0]
            = m[1][2] = m[1][3] = m[2][0]
            = m[2][1] = m[2][3] = m[3][0]
            = m[3][1] = m[3][2] 
            = 0.f;
}

Matrix4x4::Matrix4x4(float mat[4][4]) {
    m[0][0] = mat[0][0], m[0][1] = mat[0][1], m[0][2] = mat[0][2], m[0][3] = mat[0][3];
    m[1][0] = mat[1][0], m[1][1] = mat[1][1], m[1][2] = mat[1][2], m[1][3] = mat[1][3];
    m[2][0] = mat[2][0], m[2][1] = mat[2][1], m[2][2] = mat[2][2], m[2][3] = mat[2][3];
    m[3][0] = mat[3][0], m[3][1] = mat[3][1], m[3][2] = mat[3][2], m[3][3] = mat[3][3];    
}

Matrix4x4::Matrix4x4(
    float t00, float t01, float t02, float t03,
    float t10, float t11, float t12, float t13,
    float t20, float t21, float t22, float t23,
    float t30, float t31, float t32, float t33
) {
    m[0][0] = t00, m[0][1] = t01, m[0][2] = t02, m[0][3] = t03;
    m[1][0] = t10, m[1][1] = t11, m[1][2] = t12, m[1][3] = t13;
    m[2][0] = t20, m[2][1] = t21, m[2][2] = t22, m[2][3] = t23;
    m[3][0] = t30, m[3][1] = t31, m[3][2] = t32, m[3][3] = t33;
}

// Matrix4x4 public methods
bool Matrix4x4::operator==(const Matrix4x4& m2) const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m[i][j] != m2.m[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix4x4::operator!=(const Matrix4x4& m2) const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m[i][j] != m2.m[i][j]) {
                return true;
            }
        }
    }

    return false;
}

Vector3 operator*(const Matrix4x4& lhs, const Vector3& rhs) {
    auto x = rhs.x;
    auto y = rhs.y;
    auto z = rhs.z;
    return
    {
        lhs.m[0][0] * x + lhs.m[0][1] * y + lhs.m[0][2] * z,
        lhs.m[1][0] * x + lhs.m[1][1] * y + lhs.m[1][2] * z,
        lhs.m[2][0] * x + lhs.m[2][1] * y + lhs.m[2][2] * z,
    };
}

Point3 operator*(const Matrix4x4& lhs, const Point3& rhs) {
    auto x = rhs.x;
    auto y = rhs.y;
    auto z = rhs.z;
    return
    {
        lhs.m[0][0] * x + lhs.m[0][1] * y + lhs.m[0][2] * z + lhs.m[0][3] * 1,
        lhs.m[1][0] * x + lhs.m[1][1] * y + lhs.m[1][2] * z + lhs.m[1][3] * 1,
        lhs.m[2][0] * x + lhs.m[2][1] * y + lhs.m[2][2] * z + lhs.m[2][3] * 1,
    };
}

Ray operator*(const Matrix4x4& lhs, const Ray& rhs) {
    return Ray(lhs * rhs.origin, lhs * rhs.direction);
}

Matrix4x4 Matrix4x4::Mul(const Matrix4x4& m1, const Matrix4x4& m2) {
    Matrix4x4 r;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            r.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] +
                m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
        }
    }

    return r;
}

Matrix4x4 Transpose(const Matrix4x4& m) {
    return Matrix4x4(
        m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0],
        m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1],
        m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2],
        m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]
    );
}

Matrix4x4 Inverse(const Matrix4x4& m) {
    int indxc[4], indxr[4];
    int ipiv[4] = { 0, 0, 0, 0 };
    float minv[4][4];
    std::memcpy(minv, m.m, 4 * 4 * sizeof(float));
    for (int i = 0; i < 4; i++) {
        int irow = 0, icol = 0;
        float big = 0.f;
        // Choose pivot
        for (int j = 0; j < 4; j++) {
            if (ipiv[j] != 1) {
                for (int k = 0; k < 4; k++) {
                    if (ipiv[k] == 0) {
                        if (std::abs(minv[j][k]) >= big) {
                            big = float(std::abs(minv[j][k]));
                            irow = j;
                            icol = k;
                        }
                    }
                    //else if (ipiv[k] > 1)
                        //Error("Singular matrix in MatrixInvert");
                }
            }
        }
        ++ipiv[icol];
        // Swap rows _irow_ and _icol_ for pivot
        if (irow != icol) {
            for (int k = 0; k < 4; ++k) std::swap(minv[irow][k], minv[icol][k]);
        }
        indxr[i] = irow;
        indxc[i] = icol;
        //if (minv[icol][icol] == 0.f) Error("Singular matrix in MatrixInvert");

        // Set $m[icol][icol]$ to one by scaling row _icol_ appropriately
        float pivinv = 1. / minv[icol][icol];
        minv[icol][icol] = 1.;
        for (int j = 0; j < 4; j++) minv[icol][j] *= pivinv;

        // Subtract this row from others to zero out their columns
        for (int j = 0; j < 4; j++) {
            if (j != icol) {
                float save = minv[j][icol];
                minv[j][icol] = 0;
                for (int k = 0; k < 4; k++) minv[j][k] -= minv[icol][k] * save;
            }
        }
    }
    // Swap columns to reflect permutation
    for (int j = 3; j >= 0; j--) {
        if (indxr[j] != indxc[j]) {
            for (int k = 0; k < 4; k++)
                std::swap(minv[k][indxr[j]], minv[k][indxc[j]]);
        }
    }
    return Matrix4x4(minv);
}




















///////////////////////////////////////////
// Transform constructor
Transform::Transform() {}

Transform::Transform(const float mat[4][4]) {
    m = Matrix4x4(
        mat[0][0], mat[0][1], mat[0][2], mat[0][3],
        mat[1][0], mat[1][1], mat[1][2], mat[1][3],
        mat[2][0], mat[2][1], mat[2][2], mat[2][3],
        mat[3][0], mat[3][1], mat[3][2], mat[3][3]
    );
    mInv = Inverse(m);
}

Transform::Transform(const Matrix4x4& m)
    : m(m), mInv(Inverse(m))
{}

Transform::Transform(const Matrix4x4& m, const Matrix4x4& mInv)
    : m(m), mInv(mInv)
{}


// Transform Public Methods
const Matrix4x4& Transform::GetMatrix() const { return m; }

const Matrix4x4& Transform::GetInverseMatrix() const { return mInv; }

Transform Inverse(const Transform& t) {
    return Transform(t.mInv, t.m);
}

Transform Transpose(const Transform& t) {
    return Transform(Transpose(t.m), Transpose(t.mInv));
}

bool Transform::operator==(const Transform& t) const {
    return (t.m == m) && (t.mInv == mInv);
}

bool Transform::operator!=(const Transform& t) const {
    return (t.m != m) || (t.mInv != mInv);
}

bool Transform::operator<(const Transform& t2) const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (m.m[i][j] < t2.m.m[i][j]) {
                return true;
            }
            if (m.m[i][j] > t2.m.m[i][j]) {
                return false;
            }
        }
    }

    return false;
}

bool Transform::IsIdentity() const {
    return (
        m.m[0][0] == 1.f && m.m[0][1] == 0.f && m.m[0][2] == 0.f &&
        m.m[0][3] == 0.f && m.m[1][0] == 0.f && m.m[1][1] == 1.f &&
        m.m[1][2] == 0.f && m.m[1][3] == 0.f && m.m[2][0] == 0.f &&
        m.m[2][1] == 0.f && m.m[2][2] == 1.f && m.m[2][3] == 0.f &&
        m.m[3][0] == 0.f && m.m[3][1] == 0.f && m.m[3][2] == 0.f &&
        m.m[3][3] == 1.f
        );
}


// Transform Inline Functions
Point3 Transform::operator()(const Point3& p) const {
    float x = p.x, y = p.y, z = p.z;
    float xp = m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z + m.m[0][3];
    float yp = m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z + m.m[1][3];
    float zp = m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z + m.m[2][3];
    float wp = m.m[3][0] * x + m.m[3][1] * y + m.m[3][2] * z + m.m[3][3];

    if (wp == 1) {
        return Point3(xp, yp, zp);
    }
    else {
        return Point3(xp, yp, zp) / wp;
    }
}

Vector3 Transform::operator()(const Vector3& v) const {
    float x = v.x, y = v.y, z = v.z;
    return Vector3(
        m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z,
        m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z,
        m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z
        );
}

Ray Transform::operator()(const Ray& r) const {
    Point3 o = (*this)(r.origin);
    Vector3 d = (*this)(r.direction);

    return Ray(o, d);
}

Transform Transform::operator*(const Transform& t2) const {
    return Transform(Matrix4x4::Mul(m, t2.m), Matrix4x4::Mul(t2.mInv, mInv));
}

Transform Translate(const Vector3& delta) {
    Matrix4x4 m(
        1, 0, 0, delta.x,
        0, 1, 0, delta.y,
        0, 0, 1, delta.z,
        0, 0, 0, 1
    );
    Matrix4x4 minv(
        1, 0, 0, -delta.x,
        0, 1, 0, -delta.y,
        0, 0, 1, -delta.z,
        0, 0, 0, 1
    );
    return Transform(m, minv);
}

Transform Scale(float x, float y, float z) {
    Matrix4x4 m(
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    );
    Matrix4x4 minv(
        1 / x, 0, 0, 0,
        0, 1 / y, 0, 0,
        0, 0, 1 / z, 0,
        0, 0, 0, 1
    );
    return Transform(m, minv);
}

Transform RotateX(float theta) {
    float sinTheta = std::sin(Radians(theta));
    float cosTheta = std::cos(Radians(theta));
    Matrix4x4 m(
        1, 0, 0, 0,
        0, cosTheta, -sinTheta, 0,
        0, sinTheta, cosTheta, 0,
        0, 0, 0, 1
    );
    return Transform(m, Transpose(m));
}

Transform RotateY(float theta) {
    float sinTheta = std::sin(Radians(theta));
    float cosTheta = std::cos(Radians(theta));
    Matrix4x4 m(
        cosTheta, 0, sinTheta, 0,
        0, 1, 0, 0,
        -sinTheta, 0, cosTheta, 0,
        0, 0, 0, 1
    );
    return Transform(m, Transpose(m));
}

Transform RotateZ(float theta) {
    float sinTheta = std::sin(Radians(theta));
    float cosTheta = std::cos(Radians(theta));
    Matrix4x4 m(
        cosTheta, -sinTheta, 0, 0,
        sinTheta, cosTheta, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
    return Transform(m, Transpose(m));
}

Transform Rotate(float theta, const Vector3& axis) {
    Vector3 a = Normalize(axis);
    float sinTheta = std::sin(Radians(theta));
    float cosTheta = std::cos(Radians(theta));
    Matrix4x4 m;
    // Compute rotation of first basis vector
    m.m[0][0] = a.x * a.x + (1 - a.x * a.x) * cosTheta;
    m.m[0][1] = a.x * a.y * (1 - cosTheta) - a.z * sinTheta;
    m.m[0][2] = a.x * a.z * (1 - cosTheta) + a.y * sinTheta;
    m.m[0][3] = 0;

    // Compute rotations of second and third basis vectors
    m.m[1][0] = a.x * a.y * (1 - cosTheta) + a.z * sinTheta;
    m.m[1][1] = a.y * a.y + (1 - a.y * a.y) * cosTheta;
    m.m[1][2] = a.y * a.z * (1 - cosTheta) - a.x * sinTheta;
    m.m[1][3] = 0;

    m.m[2][0] = a.x * a.z * (1 - cosTheta) - a.y * sinTheta;
    m.m[2][1] = a.y * a.z * (1 - cosTheta) + a.x * sinTheta;
    m.m[2][2] = a.z * a.z + (1 - a.z * a.z) * cosTheta;
    m.m[2][3] = 0;
    return Transform(m, Transpose(m));
}

Transform LookAt(const Point3& pos, const Point3& look, const Vector3& up) {
    Matrix4x4 cameraToWorld;
    // Initialize fourth column of viewing matrix
    cameraToWorld.m[0][3] = pos.x;
    cameraToWorld.m[1][3] = pos.y;
    cameraToWorld.m[2][3] = pos.z;
    cameraToWorld.m[3][3] = 1;

    // Initialize first three columns of viewing matrix
    Vector3 dir = Normalize(look - pos);

    Vector3 right = Normalize(Cross(Normalize(up), dir));
    Vector3 newUp = Cross(dir, right);
    cameraToWorld.m[0][0] = right.x;
    cameraToWorld.m[1][0] = right.y;
    cameraToWorld.m[2][0] = right.z;
    cameraToWorld.m[3][0] = 0.;
    cameraToWorld.m[0][1] = newUp.x;
    cameraToWorld.m[1][1] = newUp.y;
    cameraToWorld.m[2][1] = newUp.z;
    cameraToWorld.m[3][1] = 0.;
    cameraToWorld.m[0][2] = dir.x;
    cameraToWorld.m[1][2] = dir.y;
    cameraToWorld.m[2][2] = dir.z;
    cameraToWorld.m[3][2] = 0.;
    return Transform(Inverse(cameraToWorld), cameraToWorld);
}

Transform Orthographic(float zNear, float zFar) {
    return Scale(1, 1, 1 / (zFar - zNear)) * Translate(Vector3(0, 0, -zNear));
}

Transform Perspective(float fov, float n, float f) {
    // Perform projective divide for perspective projection
    Matrix4x4 persp(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, (n + f) / (n - f), 2 * n * f / (f - n),
        0, 0, 1, 0
    );

    // Scale canonical perspective view to specified field of view
    float invTanAng = 1 / std::tan(Radians(fov) / 2);
    return Scale(invTanAng, invTanAng, 1) * Transform(persp);
}