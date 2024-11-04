#include "pocketpy.h"
#include "string.h"
#include "raylib.h"

#define ADD_ENUM(name) py_newint(py_emplacedict(mod, py_name(#name)), name)

static bool struct__address__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    void* ud = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)ud);
    return true;
}

#define tp_user_Quaternion tp_user_Vector4
#define tp_user_Texture2D tp_user_Texture
#define tp_user_TextureCubemap tp_user_Texture
#define tp_user_RenderTexture2D tp_user_RenderTexture
#define tp_user_Camera tp_user_Camera3D

static bool Vector2__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Vector2));
    return true;
}
static bool Vector2__init__(int argc, py_Ref argv) {
    Vector2* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Vector2));
    } else if(argc == 1 + 2) {
        if(!py_castfloat32(py_arg(1), &self->x)) return false;
        if(!py_castfloat32(py_arg(2), &self->y)) return false;
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Vector2__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector2* self = py_touserdata(argv);
    Vector2* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Vector2));
    *res = *self;
    return true;
}
static bool Vector2__get_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector2* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->x);
    return true;
}
static bool Vector2__set_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->x)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector2__get_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector2* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->y);
    return true;
}
static bool Vector2__set_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->y)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Vector2(py_GlobalRef mod) {
    py_Type type = py_newtype("Vector2", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Vector2__new__);
    py_bindmagic(type, __init__, Vector2__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Vector2__copy__);
    py_bindproperty(type, "x", Vector2__get_x, Vector2__set_x);
    py_bindproperty(type, "y", Vector2__get_y, Vector2__set_y);
    return type;
}
static py_Type tp_user_Vector2;
static bool Vector3__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Vector3));
    return true;
}
static bool Vector3__init__(int argc, py_Ref argv) {
    Vector3* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Vector3));
    } else if(argc == 1 + 3) {
        if(!py_castfloat32(py_arg(1), &self->x)) return false;
        if(!py_castfloat32(py_arg(2), &self->y)) return false;
        if(!py_castfloat32(py_arg(3), &self->z)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Vector3__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector3* self = py_touserdata(argv);
    Vector3* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Vector3));
    *res = *self;
    return true;
}
static bool Vector3__get_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector3* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->x);
    return true;
}
static bool Vector3__set_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector3* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->x)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector3__get_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector3* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->y);
    return true;
}
static bool Vector3__set_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector3* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->y)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector3__get_z(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector3* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->z);
    return true;
}
static bool Vector3__set_z(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector3* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->z)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Vector3(py_GlobalRef mod) {
    py_Type type = py_newtype("Vector3", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Vector3__new__);
    py_bindmagic(type, __init__, Vector3__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Vector3__copy__);
    py_bindproperty(type, "x", Vector3__get_x, Vector3__set_x);
    py_bindproperty(type, "y", Vector3__get_y, Vector3__set_y);
    py_bindproperty(type, "z", Vector3__get_z, Vector3__set_z);
    return type;
}
static py_Type tp_user_Vector3;
static bool Vector4__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Vector4));
    return true;
}
static bool Vector4__init__(int argc, py_Ref argv) {
    Vector4* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Vector4));
    } else if(argc == 1 + 4) {
        if(!py_castfloat32(py_arg(1), &self->x)) return false;
        if(!py_castfloat32(py_arg(2), &self->y)) return false;
        if(!py_castfloat32(py_arg(3), &self->z)) return false;
        if(!py_castfloat32(py_arg(4), &self->w)) return false;
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Vector4__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4* self = py_touserdata(argv);
    Vector4* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Vector4));
    *res = *self;
    return true;
}
static bool Vector4__get_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->x);
    return true;
}
static bool Vector4__set_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector4* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->x)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector4__get_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->y);
    return true;
}
static bool Vector4__set_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector4* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->y)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector4__get_z(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->z);
    return true;
}
static bool Vector4__set_z(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector4* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->z)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Vector4__get_w(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->w);
    return true;
}
static bool Vector4__set_w(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector4* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->w)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Vector4(py_GlobalRef mod) {
    py_Type type = py_newtype("Vector4", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Vector4__new__);
    py_bindmagic(type, __init__, Vector4__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Vector4__copy__);
    py_bindproperty(type, "x", Vector4__get_x, Vector4__set_x);
    py_bindproperty(type, "y", Vector4__get_y, Vector4__set_y);
    py_bindproperty(type, "z", Vector4__get_z, Vector4__set_z);
    py_bindproperty(type, "w", Vector4__get_w, Vector4__set_w);
    return type;
}
static py_Type tp_user_Vector4;
static bool Matrix__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Matrix));
    return true;
}
static bool Matrix__init__(int argc, py_Ref argv) {
    Matrix* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Matrix));
    } else if(argc == 1 + 16) {
        if(!py_castfloat32(py_arg(1), &self->m0)) return false;
        if(!py_castfloat32(py_arg(2), &self->m4)) return false;
        if(!py_castfloat32(py_arg(3), &self->m8)) return false;
        if(!py_castfloat32(py_arg(4), &self->m12)) return false;
        if(!py_castfloat32(py_arg(5), &self->m1)) return false;
        if(!py_castfloat32(py_arg(6), &self->m5)) return false;
        if(!py_castfloat32(py_arg(7), &self->m9)) return false;
        if(!py_castfloat32(py_arg(8), &self->m13)) return false;
        if(!py_castfloat32(py_arg(9), &self->m2)) return false;
        if(!py_castfloat32(py_arg(10), &self->m6)) return false;
        if(!py_castfloat32(py_arg(11), &self->m10)) return false;
        if(!py_castfloat32(py_arg(12), &self->m14)) return false;
        if(!py_castfloat32(py_arg(13), &self->m3)) return false;
        if(!py_castfloat32(py_arg(14), &self->m7)) return false;
        if(!py_castfloat32(py_arg(15), &self->m11)) return false;
        if(!py_castfloat32(py_arg(16), &self->m15)) return false;
    } else {
        return TypeError("expected 1 or 17 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Matrix__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    Matrix* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Matrix));
    *res = *self;
    return true;
}
static bool Matrix__get_m0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m0);
    return true;
}
static bool Matrix__set_m0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m0)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m4(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m4);
    return true;
}
static bool Matrix__set_m4(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m4)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m8(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m8);
    return true;
}
static bool Matrix__set_m8(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m8)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m12(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m12);
    return true;
}
static bool Matrix__set_m12(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m12)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m1);
    return true;
}
static bool Matrix__set_m1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m1)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m5(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m5);
    return true;
}
static bool Matrix__set_m5(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m5)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m9(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m9);
    return true;
}
static bool Matrix__set_m9(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m9)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m13(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m13);
    return true;
}
static bool Matrix__set_m13(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m13)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m2);
    return true;
}
static bool Matrix__set_m2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m2)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m6(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m6);
    return true;
}
static bool Matrix__set_m6(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m6)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m10(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m10);
    return true;
}
static bool Matrix__set_m10(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m10)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m14(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m14);
    return true;
}
static bool Matrix__set_m14(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m14)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m3(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m3);
    return true;
}
static bool Matrix__set_m3(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m3)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m7(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m7);
    return true;
}
static bool Matrix__set_m7(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m7)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m11(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m11);
    return true;
}
static bool Matrix__set_m11(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m11)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Matrix__get_m15(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Matrix* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->m15);
    return true;
}
static bool Matrix__set_m15(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Matrix* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->m15)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Matrix(py_GlobalRef mod) {
    py_Type type = py_newtype("Matrix", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Matrix__new__);
    py_bindmagic(type, __init__, Matrix__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Matrix__copy__);
    py_bindproperty(type, "m0", Matrix__get_m0, Matrix__set_m0);
    py_bindproperty(type, "m4", Matrix__get_m4, Matrix__set_m4);
    py_bindproperty(type, "m8", Matrix__get_m8, Matrix__set_m8);
    py_bindproperty(type, "m12", Matrix__get_m12, Matrix__set_m12);
    py_bindproperty(type, "m1", Matrix__get_m1, Matrix__set_m1);
    py_bindproperty(type, "m5", Matrix__get_m5, Matrix__set_m5);
    py_bindproperty(type, "m9", Matrix__get_m9, Matrix__set_m9);
    py_bindproperty(type, "m13", Matrix__get_m13, Matrix__set_m13);
    py_bindproperty(type, "m2", Matrix__get_m2, Matrix__set_m2);
    py_bindproperty(type, "m6", Matrix__get_m6, Matrix__set_m6);
    py_bindproperty(type, "m10", Matrix__get_m10, Matrix__set_m10);
    py_bindproperty(type, "m14", Matrix__get_m14, Matrix__set_m14);
    py_bindproperty(type, "m3", Matrix__get_m3, Matrix__set_m3);
    py_bindproperty(type, "m7", Matrix__get_m7, Matrix__set_m7);
    py_bindproperty(type, "m11", Matrix__get_m11, Matrix__set_m11);
    py_bindproperty(type, "m15", Matrix__get_m15, Matrix__set_m15);
    return type;
}
static py_Type tp_user_Matrix;
static bool Color__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Color));
    return true;
}
static bool Color__init__(int argc, py_Ref argv) {
    Color* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Color));
    } else if(argc == 1 + 4) {
        if(!py_checkint(py_arg(1))) return false;
        self->r = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->g = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->b = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->a = py_toint(py_arg(4));
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Color__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color* self = py_touserdata(argv);
    Color* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Color));
    *res = *self;
    return true;
}
static bool Color__get_r(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color* self = py_touserdata(argv);
    py_newint(py_retval(), self->r);
    return true;
}
static bool Color__set_r(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->r = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Color__get_g(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color* self = py_touserdata(argv);
    py_newint(py_retval(), self->g);
    return true;
}
static bool Color__set_g(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->g = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Color__get_b(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color* self = py_touserdata(argv);
    py_newint(py_retval(), self->b);
    return true;
}
static bool Color__set_b(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->b = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Color__get_a(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color* self = py_touserdata(argv);
    py_newint(py_retval(), self->a);
    return true;
}
static bool Color__set_a(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->a = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Color(py_GlobalRef mod) {
    py_Type type = py_newtype("Color", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Color__new__);
    py_bindmagic(type, __init__, Color__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Color__copy__);
    py_bindproperty(type, "r", Color__get_r, Color__set_r);
    py_bindproperty(type, "g", Color__get_g, Color__set_g);
    py_bindproperty(type, "b", Color__get_b, Color__set_b);
    py_bindproperty(type, "a", Color__get_a, Color__set_a);
    return type;
}
static py_Type tp_user_Color;
static bool Rectangle__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Rectangle));
    return true;
}
static bool Rectangle__init__(int argc, py_Ref argv) {
    Rectangle* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Rectangle));
    } else if(argc == 1 + 4) {
        if(!py_castfloat32(py_arg(1), &self->x)) return false;
        if(!py_castfloat32(py_arg(2), &self->y)) return false;
        if(!py_castfloat32(py_arg(3), &self->width)) return false;
        if(!py_castfloat32(py_arg(4), &self->height)) return false;
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Rectangle__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Rectangle* self = py_touserdata(argv);
    Rectangle* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Rectangle));
    *res = *self;
    return true;
}
static bool Rectangle__get_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Rectangle* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->x);
    return true;
}
static bool Rectangle__set_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->x)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Rectangle__get_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Rectangle* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->y);
    return true;
}
static bool Rectangle__set_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->y)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Rectangle__get_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Rectangle* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->width);
    return true;
}
static bool Rectangle__set_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->width)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Rectangle__get_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Rectangle* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->height);
    return true;
}
static bool Rectangle__set_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->height)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Rectangle(py_GlobalRef mod) {
    py_Type type = py_newtype("Rectangle", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Rectangle__new__);
    py_bindmagic(type, __init__, Rectangle__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Rectangle__copy__);
    py_bindproperty(type, "x", Rectangle__get_x, Rectangle__set_x);
    py_bindproperty(type, "y", Rectangle__get_y, Rectangle__set_y);
    py_bindproperty(type, "width", Rectangle__get_width, Rectangle__set_width);
    py_bindproperty(type, "height", Rectangle__get_height, Rectangle__set_height);
    return type;
}
static py_Type tp_user_Rectangle;
static bool Image__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Image));
    return true;
}
static bool Image__init__(int argc, py_Ref argv) {
    Image* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Image));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->data = (void *)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->width = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->height = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->mipmaps = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->format = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Image__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    Image* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Image));
    *res = *self;
    return true;
}
static bool Image__get_data(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->data);
    return true;
}
static bool Image__set_data(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->data = (void *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Image__get_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    py_newint(py_retval(), self->width);
    return true;
}
static bool Image__set_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->width = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Image__get_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    py_newint(py_retval(), self->height);
    return true;
}
static bool Image__set_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->height = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Image__get_mipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    py_newint(py_retval(), self->mipmaps);
    return true;
}
static bool Image__set_mipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->mipmaps = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Image__get_format(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image* self = py_touserdata(argv);
    py_newint(py_retval(), self->format);
    return true;
}
static bool Image__set_format(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->format = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Image(py_GlobalRef mod) {
    py_Type type = py_newtype("Image", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Image__new__);
    py_bindmagic(type, __init__, Image__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Image__copy__);
    py_bindproperty(type, "data", Image__get_data, Image__set_data);
    py_bindproperty(type, "width", Image__get_width, Image__set_width);
    py_bindproperty(type, "height", Image__get_height, Image__set_height);
    py_bindproperty(type, "mipmaps", Image__get_mipmaps, Image__set_mipmaps);
    py_bindproperty(type, "format", Image__get_format, Image__set_format);
    return type;
}
static py_Type tp_user_Image;
static bool Texture__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Texture));
    return true;
}
static bool Texture__init__(int argc, py_Ref argv) {
    Texture* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Texture));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->id = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->width = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->height = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->mipmaps = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->format = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Texture__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    Texture* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Texture));
    *res = *self;
    return true;
}
static bool Texture__get_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    py_newint(py_retval(), self->id);
    return true;
}
static bool Texture__set_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->id = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Texture__get_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    py_newint(py_retval(), self->width);
    return true;
}
static bool Texture__set_width(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->width = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Texture__get_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    py_newint(py_retval(), self->height);
    return true;
}
static bool Texture__set_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->height = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Texture__get_mipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    py_newint(py_retval(), self->mipmaps);
    return true;
}
static bool Texture__set_mipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->mipmaps = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Texture__get_format(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture* self = py_touserdata(argv);
    py_newint(py_retval(), self->format);
    return true;
}
static bool Texture__set_format(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->format = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Texture(py_GlobalRef mod) {
    py_Type type = py_newtype("Texture", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Texture__new__);
    py_bindmagic(type, __init__, Texture__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Texture__copy__);
    py_bindproperty(type, "id", Texture__get_id, Texture__set_id);
    py_bindproperty(type, "width", Texture__get_width, Texture__set_width);
    py_bindproperty(type, "height", Texture__get_height, Texture__set_height);
    py_bindproperty(type, "mipmaps", Texture__get_mipmaps, Texture__set_mipmaps);
    py_bindproperty(type, "format", Texture__get_format, Texture__set_format);
    return type;
}
static py_Type tp_user_Texture;
static bool RenderTexture__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(RenderTexture));
    return true;
}
static bool RenderTexture__init__(int argc, py_Ref argv) {
    RenderTexture* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(RenderTexture));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->id = py_toint(py_arg(1));
        do {
            if(!py_checktype(py_arg(2), tp_user_Texture)) return false;
            self->texture = *(Texture*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_Texture)) return false;
            self->depth = *(Texture*)py_touserdata(py_arg(3));
        } while(0);
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool RenderTexture__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture* self = py_touserdata(argv);
    RenderTexture* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(RenderTexture));
    *res = *self;
    return true;
}
static bool RenderTexture__get_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture* self = py_touserdata(argv);
    py_newint(py_retval(), self->id);
    return true;
}
static bool RenderTexture__set_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RenderTexture* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->id = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool RenderTexture__get_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture* self = py_touserdata(argv);
    do {
        Texture* ud = py_newobject(py_retval(), tp_user_Texture, 0, sizeof(Texture));
        *ud = self->texture;
    } while(0);
    return true;
}
static bool RenderTexture__set_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RenderTexture* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture)) return false;
        self->texture = *(Texture*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool RenderTexture__get_depth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture* self = py_touserdata(argv);
    do {
        Texture* ud = py_newobject(py_retval(), tp_user_Texture, 0, sizeof(Texture));
        *ud = self->depth;
    } while(0);
    return true;
}
static bool RenderTexture__set_depth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RenderTexture* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture)) return false;
        self->depth = *(Texture*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__RenderTexture(py_GlobalRef mod) {
    py_Type type = py_newtype("RenderTexture", tp_object, mod, NULL);
    py_bindmagic(type, __new__, RenderTexture__new__);
    py_bindmagic(type, __init__, RenderTexture__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", RenderTexture__copy__);
    py_bindproperty(type, "id", RenderTexture__get_id, RenderTexture__set_id);
    py_bindproperty(type, "texture", RenderTexture__get_texture, RenderTexture__set_texture);
    py_bindproperty(type, "depth", RenderTexture__get_depth, RenderTexture__set_depth);
    return type;
}
static py_Type tp_user_RenderTexture;
static bool NPatchInfo__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(NPatchInfo));
    return true;
}
static bool NPatchInfo__init__(int argc, py_Ref argv) {
    NPatchInfo* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(NPatchInfo));
    } else if(argc == 1 + 6) {
        do {
            if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
            self->source = *(Rectangle*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->left = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->top = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->right = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->bottom = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->layout = py_toint(py_arg(6));
    } else {
        return TypeError("expected 1 or 7 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    NPatchInfo* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(NPatchInfo));
    *res = *self;
    return true;
}
static bool NPatchInfo__get_source(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    do {
        Rectangle* ud = py_newobject(py_retval(), tp_user_Rectangle, 0, sizeof(Rectangle));
        *ud = self->source;
    } while(0);
    return true;
}
static bool NPatchInfo__set_source(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        self->source = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__get_left(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->left);
    return true;
}
static bool NPatchInfo__set_left(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->left = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__get_top(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->top);
    return true;
}
static bool NPatchInfo__set_top(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->top = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__get_right(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->right);
    return true;
}
static bool NPatchInfo__set_right(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->right = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__get_bottom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->bottom);
    return true;
}
static bool NPatchInfo__set_bottom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->bottom = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool NPatchInfo__get_layout(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    NPatchInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->layout);
    return true;
}
static bool NPatchInfo__set_layout(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    NPatchInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->layout = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__NPatchInfo(py_GlobalRef mod) {
    py_Type type = py_newtype("NPatchInfo", tp_object, mod, NULL);
    py_bindmagic(type, __new__, NPatchInfo__new__);
    py_bindmagic(type, __init__, NPatchInfo__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", NPatchInfo__copy__);
    py_bindproperty(type, "source", NPatchInfo__get_source, NPatchInfo__set_source);
    py_bindproperty(type, "left", NPatchInfo__get_left, NPatchInfo__set_left);
    py_bindproperty(type, "top", NPatchInfo__get_top, NPatchInfo__set_top);
    py_bindproperty(type, "right", NPatchInfo__get_right, NPatchInfo__set_right);
    py_bindproperty(type, "bottom", NPatchInfo__get_bottom, NPatchInfo__set_bottom);
    py_bindproperty(type, "layout", NPatchInfo__get_layout, NPatchInfo__set_layout);
    return type;
}
static py_Type tp_user_NPatchInfo;
static bool GlyphInfo__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(GlyphInfo));
    return true;
}
static bool GlyphInfo__init__(int argc, py_Ref argv) {
    GlyphInfo* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(GlyphInfo));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->value = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->offsetX = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->offsetY = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->advanceX = py_toint(py_arg(4));
        do {
            if(!py_checktype(py_arg(5), tp_user_Image)) return false;
            self->image = *(Image*)py_touserdata(py_arg(5));
        } while(0);
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool GlyphInfo__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    GlyphInfo* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(GlyphInfo));
    *res = *self;
    return true;
}
static bool GlyphInfo__get_value(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->value);
    return true;
}
static bool GlyphInfo__set_value(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->value = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool GlyphInfo__get_offsetX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->offsetX);
    return true;
}
static bool GlyphInfo__set_offsetX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->offsetX = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool GlyphInfo__get_offsetY(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->offsetY);
    return true;
}
static bool GlyphInfo__set_offsetY(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->offsetY = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool GlyphInfo__get_advanceX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->advanceX);
    return true;
}
static bool GlyphInfo__set_advanceX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->advanceX = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool GlyphInfo__get_image(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    GlyphInfo* self = py_touserdata(argv);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = self->image;
    } while(0);
    return true;
}
static bool GlyphInfo__set_image(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Image)) return false;
        self->image = *(Image*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__GlyphInfo(py_GlobalRef mod) {
    py_Type type = py_newtype("GlyphInfo", tp_object, mod, NULL);
    py_bindmagic(type, __new__, GlyphInfo__new__);
    py_bindmagic(type, __init__, GlyphInfo__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", GlyphInfo__copy__);
    py_bindproperty(type, "value", GlyphInfo__get_value, GlyphInfo__set_value);
    py_bindproperty(type, "offsetX", GlyphInfo__get_offsetX, GlyphInfo__set_offsetX);
    py_bindproperty(type, "offsetY", GlyphInfo__get_offsetY, GlyphInfo__set_offsetY);
    py_bindproperty(type, "advanceX", GlyphInfo__get_advanceX, GlyphInfo__set_advanceX);
    py_bindproperty(type, "image", GlyphInfo__get_image, GlyphInfo__set_image);
    return type;
}
static py_Type tp_user_GlyphInfo;
static bool Font__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Font));
    return true;
}
static bool Font__init__(int argc, py_Ref argv) {
    Font* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Font));
    } else if(argc == 1 + 6) {
        if(!py_checkint(py_arg(1))) return false;
        self->baseSize = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->glyphCount = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->glyphPadding = py_toint(py_arg(3));
        do {
            if(!py_checktype(py_arg(4), tp_user_Texture2D)) return false;
            self->texture = *(Texture2D*)py_touserdata(py_arg(4));
        } while(0);
        if(!py_checkint(py_arg(5))) return false;
        self->recs = (Rectangle *)py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->glyphs = (GlyphInfo *)py_toint(py_arg(6));
    } else {
        return TypeError("expected 1 or 7 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Font__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    Font* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Font));
    *res = *self;
    return true;
}
static bool Font__get_baseSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    py_newint(py_retval(), self->baseSize);
    return true;
}
static bool Font__set_baseSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->baseSize = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Font__get_glyphCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    py_newint(py_retval(), self->glyphCount);
    return true;
}
static bool Font__set_glyphCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->glyphCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Font__get_glyphPadding(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    py_newint(py_retval(), self->glyphPadding);
    return true;
}
static bool Font__set_glyphPadding(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->glyphPadding = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Font__get_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    do {
        Texture2D* ud = py_newobject(py_retval(), tp_user_Texture2D, 0, sizeof(Texture2D));
        *ud = self->texture;
    } while(0);
    return true;
}
static bool Font__set_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
        self->texture = *(Texture2D*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Font__get_recs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->recs);
    return true;
}
static bool Font__set_recs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->recs = (Rectangle *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Font__get_glyphs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->glyphs);
    return true;
}
static bool Font__set_glyphs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->glyphs = (GlyphInfo *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Font(py_GlobalRef mod) {
    py_Type type = py_newtype("Font", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Font__new__);
    py_bindmagic(type, __init__, Font__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Font__copy__);
    py_bindproperty(type, "baseSize", Font__get_baseSize, Font__set_baseSize);
    py_bindproperty(type, "glyphCount", Font__get_glyphCount, Font__set_glyphCount);
    py_bindproperty(type, "glyphPadding", Font__get_glyphPadding, Font__set_glyphPadding);
    py_bindproperty(type, "texture", Font__get_texture, Font__set_texture);
    py_bindproperty(type, "recs", Font__get_recs, Font__set_recs);
    py_bindproperty(type, "glyphs", Font__get_glyphs, Font__set_glyphs);
    return type;
}
static py_Type tp_user_Font;
static bool Camera3D__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Camera3D));
    return true;
}
static bool Camera3D__init__(int argc, py_Ref argv) {
    Camera3D* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Camera3D));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(1));
            self->position = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(2));
            self->target = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(3));
            self->up = *(Vector3*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->fovy)) return false;
        if(!py_checkint(py_arg(5))) return false;
        self->projection = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Camera3D__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    Camera3D* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Camera3D));
    *res = *self;
    return true;
}
static bool Camera3D__get_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->position));
    return true;
}
static bool Camera3D__set_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera3D* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->position = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Camera3D__get_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->target));
    return true;
}
static bool Camera3D__set_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera3D* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->target = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Camera3D__get_up(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->up));
    return true;
}
static bool Camera3D__set_up(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera3D* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->up = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Camera3D__get_fovy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->fovy);
    return true;
}
static bool Camera3D__set_fovy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera3D* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->fovy)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Camera3D__get_projection(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D* self = py_touserdata(argv);
    py_newint(py_retval(), self->projection);
    return true;
}
static bool Camera3D__set_projection(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera3D* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->projection = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Camera3D(py_GlobalRef mod) {
    py_Type type = py_newtype("Camera3D", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Camera3D__new__);
    py_bindmagic(type, __init__, Camera3D__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Camera3D__copy__);
    py_bindproperty(type, "position", Camera3D__get_position, Camera3D__set_position);
    py_bindproperty(type, "target", Camera3D__get_target, Camera3D__set_target);
    py_bindproperty(type, "up", Camera3D__get_up, Camera3D__set_up);
    py_bindproperty(type, "fovy", Camera3D__get_fovy, Camera3D__set_fovy);
    py_bindproperty(type, "projection", Camera3D__get_projection, Camera3D__set_projection);
    return type;
}
static py_Type tp_user_Camera3D;
static bool Camera2D__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Camera2D));
    return true;
}
static bool Camera2D__init__(int argc, py_Ref argv) {
    Camera2D* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Camera2D));
    } else if(argc == 1 + 4) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->offset = *(Vector2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->target = *(Vector2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->rotation)) return false;
        if(!py_castfloat32(py_arg(4), &self->zoom)) return false;
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Camera2D__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D* self = py_touserdata(argv);
    Camera2D* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Camera2D));
    *res = *self;
    return true;
}
static bool Camera2D__get_offset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->offset));
    return true;
}
static bool Camera2D__set_offset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera2D* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->offset = *(Vector2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Camera2D__get_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->target));
    return true;
}
static bool Camera2D__set_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera2D* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->target = *(Vector2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Camera2D__get_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->rotation);
    return true;
}
static bool Camera2D__set_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera2D* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->rotation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool Camera2D__get_zoom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->zoom);
    return true;
}
static bool Camera2D__set_zoom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera2D* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->zoom)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__Camera2D(py_GlobalRef mod) {
    py_Type type = py_newtype("Camera2D", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Camera2D__new__);
    py_bindmagic(type, __init__, Camera2D__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Camera2D__copy__);
    py_bindproperty(type, "offset", Camera2D__get_offset, Camera2D__set_offset);
    py_bindproperty(type, "target", Camera2D__get_target, Camera2D__set_target);
    py_bindproperty(type, "rotation", Camera2D__get_rotation, Camera2D__set_rotation);
    py_bindproperty(type, "zoom", Camera2D__get_zoom, Camera2D__set_zoom);
    return type;
}
static py_Type tp_user_Camera2D;
static bool Mesh__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Mesh));
    return true;
}
static bool Mesh__init__(int argc, py_Ref argv) {
    Mesh* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Mesh));
    } else if(argc == 1 + 17) {
        if(!py_checkint(py_arg(1))) return false;
        self->vertexCount = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->triangleCount = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->vertices = (float *)py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->texcoords = (float *)py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->texcoords2 = (float *)py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->normals = (float *)py_toint(py_arg(6));
        if(!py_checkint(py_arg(7))) return false;
        self->tangents = (float *)py_toint(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->colors = (unsigned char *)py_toint(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->indices = (unsigned short *)py_toint(py_arg(9));
        if(!py_checkint(py_arg(10))) return false;
        self->animVertices = (float *)py_toint(py_arg(10));
        if(!py_checkint(py_arg(11))) return false;
        self->animNormals = (float *)py_toint(py_arg(11));
        if(!py_checkint(py_arg(12))) return false;
        self->boneIds = (unsigned char *)py_toint(py_arg(12));
        if(!py_checkint(py_arg(13))) return false;
        self->boneWeights = (float *)py_toint(py_arg(13));
        if(!py_checkint(py_arg(14))) return false;
        self->boneMatrices = (Matrix *)py_toint(py_arg(14));
        if(!py_checkint(py_arg(15))) return false;
        self->boneCount = py_toint(py_arg(15));
        if(!py_checkint(py_arg(16))) return false;
        self->vaoId = py_toint(py_arg(16));
        if(!py_checkint(py_arg(17))) return false;
        self->vboId = (unsigned int *)py_toint(py_arg(17));
    } else {
        return TypeError("expected 1 or 18 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Mesh__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    Mesh* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Mesh));
    *res = *self;
    return true;
}
static bool Mesh__get_vertexCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), self->vertexCount);
    return true;
}
static bool Mesh__set_vertexCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->vertexCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_triangleCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), self->triangleCount);
    return true;
}
static bool Mesh__set_triangleCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->triangleCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_vertices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->vertices);
    return true;
}
static bool Mesh__set_vertices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->vertices = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_texcoords(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->texcoords);
    return true;
}
static bool Mesh__set_texcoords(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->texcoords = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_texcoords2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->texcoords2);
    return true;
}
static bool Mesh__set_texcoords2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->texcoords2 = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_normals(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->normals);
    return true;
}
static bool Mesh__set_normals(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->normals = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_tangents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->tangents);
    return true;
}
static bool Mesh__set_tangents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->tangents = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_colors(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->colors);
    return true;
}
static bool Mesh__set_colors(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->colors = (unsigned char *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_indices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->indices);
    return true;
}
static bool Mesh__set_indices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->indices = (unsigned short *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_animVertices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->animVertices);
    return true;
}
static bool Mesh__set_animVertices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->animVertices = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_animNormals(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->animNormals);
    return true;
}
static bool Mesh__set_animNormals(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->animNormals = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_boneIds(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->boneIds);
    return true;
}
static bool Mesh__set_boneIds(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneIds = (unsigned char *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_boneWeights(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->boneWeights);
    return true;
}
static bool Mesh__set_boneWeights(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneWeights = (float *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_boneMatrices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->boneMatrices);
    return true;
}
static bool Mesh__set_boneMatrices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneMatrices = (Matrix *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), self->boneCount);
    return true;
}
static bool Mesh__set_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_vaoId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), self->vaoId);
    return true;
}
static bool Mesh__set_vaoId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->vaoId = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Mesh__get_vboId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->vboId);
    return true;
}
static bool Mesh__set_vboId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->vboId = (unsigned int *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Mesh(py_GlobalRef mod) {
    py_Type type = py_newtype("Mesh", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Mesh__new__);
    py_bindmagic(type, __init__, Mesh__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Mesh__copy__);
    py_bindproperty(type, "vertexCount", Mesh__get_vertexCount, Mesh__set_vertexCount);
    py_bindproperty(type, "triangleCount", Mesh__get_triangleCount, Mesh__set_triangleCount);
    py_bindproperty(type, "vertices", Mesh__get_vertices, Mesh__set_vertices);
    py_bindproperty(type, "texcoords", Mesh__get_texcoords, Mesh__set_texcoords);
    py_bindproperty(type, "texcoords2", Mesh__get_texcoords2, Mesh__set_texcoords2);
    py_bindproperty(type, "normals", Mesh__get_normals, Mesh__set_normals);
    py_bindproperty(type, "tangents", Mesh__get_tangents, Mesh__set_tangents);
    py_bindproperty(type, "colors", Mesh__get_colors, Mesh__set_colors);
    py_bindproperty(type, "indices", Mesh__get_indices, Mesh__set_indices);
    py_bindproperty(type, "animVertices", Mesh__get_animVertices, Mesh__set_animVertices);
    py_bindproperty(type, "animNormals", Mesh__get_animNormals, Mesh__set_animNormals);
    py_bindproperty(type, "boneIds", Mesh__get_boneIds, Mesh__set_boneIds);
    py_bindproperty(type, "boneWeights", Mesh__get_boneWeights, Mesh__set_boneWeights);
    py_bindproperty(type, "boneMatrices", Mesh__get_boneMatrices, Mesh__set_boneMatrices);
    py_bindproperty(type, "boneCount", Mesh__get_boneCount, Mesh__set_boneCount);
    py_bindproperty(type, "vaoId", Mesh__get_vaoId, Mesh__set_vaoId);
    py_bindproperty(type, "vboId", Mesh__get_vboId, Mesh__set_vboId);
    return type;
}
static py_Type tp_user_Mesh;
static bool Shader__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Shader));
    return true;
}
static bool Shader__init__(int argc, py_Ref argv) {
    Shader* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Shader));
    } else if(argc == 1 + 2) {
        if(!py_checkint(py_arg(1))) return false;
        self->id = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->locs = (int *)py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Shader__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader* self = py_touserdata(argv);
    Shader* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Shader));
    *res = *self;
    return true;
}
static bool Shader__get_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader* self = py_touserdata(argv);
    py_newint(py_retval(), self->id);
    return true;
}
static bool Shader__set_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Shader* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->id = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Shader__get_locs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->locs);
    return true;
}
static bool Shader__set_locs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Shader* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->locs = (int *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Shader(py_GlobalRef mod) {
    py_Type type = py_newtype("Shader", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Shader__new__);
    py_bindmagic(type, __init__, Shader__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Shader__copy__);
    py_bindproperty(type, "id", Shader__get_id, Shader__set_id);
    py_bindproperty(type, "locs", Shader__get_locs, Shader__set_locs);
    return type;
}
static py_Type tp_user_Shader;
static bool MaterialMap__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(MaterialMap));
    return true;
}
static bool MaterialMap__init__(int argc, py_Ref argv) {
    MaterialMap* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(MaterialMap));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
            self->texture = *(Texture2D*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_Color)) return false;
            self->color = *(Color*)py_touserdata(py_arg(2));
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->value)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool MaterialMap__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    MaterialMap* self = py_touserdata(argv);
    MaterialMap* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(MaterialMap));
    *res = *self;
    return true;
}
static bool MaterialMap__get_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    MaterialMap* self = py_touserdata(argv);
    do {
        Texture2D* ud = py_newobject(py_retval(), tp_user_Texture2D, 0, sizeof(Texture2D));
        *ud = self->texture;
    } while(0);
    return true;
}
static bool MaterialMap__set_texture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    MaterialMap* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
        self->texture = *(Texture2D*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool MaterialMap__get_color(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    MaterialMap* self = py_touserdata(argv);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = self->color;
    } while(0);
    return true;
}
static bool MaterialMap__set_color(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    MaterialMap* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        self->color = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool MaterialMap__get_value(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    MaterialMap* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->value);
    return true;
}
static bool MaterialMap__set_value(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    MaterialMap* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->value)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__MaterialMap(py_GlobalRef mod) {
    py_Type type = py_newtype("MaterialMap", tp_object, mod, NULL);
    py_bindmagic(type, __new__, MaterialMap__new__);
    py_bindmagic(type, __init__, MaterialMap__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", MaterialMap__copy__);
    py_bindproperty(type, "texture", MaterialMap__get_texture, MaterialMap__set_texture);
    py_bindproperty(type, "color", MaterialMap__get_color, MaterialMap__set_color);
    py_bindproperty(type, "value", MaterialMap__get_value, MaterialMap__set_value);
    return type;
}
static py_Type tp_user_MaterialMap;
static bool Material__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Material));
    return true;
}
static bool Material__init__(int argc, py_Ref argv) {
    Material* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Material));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_user_Shader)) return false;
            self->shader = *(Shader*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->maps = (MaterialMap *)py_toint(py_arg(2));
        // _2 params is read-only
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Material__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material* self = py_touserdata(argv);
    Material* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Material));
    *res = *self;
    return true;
}
static bool Material__get_shader(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material* self = py_touserdata(argv);
    do {
        Shader* ud = py_newobject(py_retval(), tp_user_Shader, 0, sizeof(Shader));
        *ud = self->shader;
    } while(0);
    return true;
}
static bool Material__set_shader(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Material* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Shader)) return false;
        self->shader = *(Shader*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Material__get_maps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->maps);
    return true;
}
static bool Material__set_maps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Material* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->maps = (MaterialMap *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Material__get_params(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->params);
    return true;
}
static py_Type register__Material(py_GlobalRef mod) {
    py_Type type = py_newtype("Material", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Material__new__);
    py_bindmagic(type, __init__, Material__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Material__copy__);
    py_bindproperty(type, "shader", Material__get_shader, Material__set_shader);
    py_bindproperty(type, "maps", Material__get_maps, Material__set_maps);
    py_bindproperty(type, "params", Material__get_params, NULL);
    return type;
}
static py_Type tp_user_Material;
static bool Transform__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Transform));
    return true;
}
static bool Transform__init__(int argc, py_Ref argv) {
    Transform* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Transform));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(1));
            self->translation = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_Quaternion)) return false;
            self->rotation = *(Quaternion*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(3));
            self->scale = *(Vector3*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Transform__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Transform* self = py_touserdata(argv);
    Transform* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Transform));
    *res = *self;
    return true;
}
static bool Transform__get_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Transform* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->translation));
    return true;
}
static bool Transform__set_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Transform* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->translation = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Transform__get_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Transform* self = py_touserdata(argv);
    do {
        Quaternion* ud = py_newobject(py_retval(), tp_user_Quaternion, 0, sizeof(Quaternion));
        *ud = self->rotation;
    } while(0);
    return true;
}
static bool Transform__set_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Transform* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Quaternion)) return false;
        self->rotation = *(Quaternion*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Transform__get_scale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Transform* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->scale));
    return true;
}
static bool Transform__set_scale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Transform* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->scale = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__Transform(py_GlobalRef mod) {
    py_Type type = py_newtype("Transform", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Transform__new__);
    py_bindmagic(type, __init__, Transform__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Transform__copy__);
    py_bindproperty(type, "translation", Transform__get_translation, Transform__set_translation);
    py_bindproperty(type, "rotation", Transform__get_rotation, Transform__set_rotation);
    py_bindproperty(type, "scale", Transform__get_scale, Transform__set_scale);
    return type;
}
static py_Type tp_user_Transform;
static bool BoneInfo__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(BoneInfo));
    return true;
}
static bool BoneInfo__init__(int argc, py_Ref argv) {
    BoneInfo* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(BoneInfo));
    } else if(argc == 1 + 2) {
        // _0 name is read-only
        if(!py_checkint(py_arg(2))) return false;
        self->parent = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool BoneInfo__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoneInfo* self = py_touserdata(argv);
    BoneInfo* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(BoneInfo));
    *res = *self;
    return true;
}
static bool BoneInfo__get_name(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoneInfo* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->name);
    return true;
}
static bool BoneInfo__get_parent(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoneInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->parent);
    return true;
}
static bool BoneInfo__set_parent(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    BoneInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->parent = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__BoneInfo(py_GlobalRef mod) {
    py_Type type = py_newtype("BoneInfo", tp_object, mod, NULL);
    py_bindmagic(type, __new__, BoneInfo__new__);
    py_bindmagic(type, __init__, BoneInfo__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", BoneInfo__copy__);
    py_bindproperty(type, "name", BoneInfo__get_name, NULL);
    py_bindproperty(type, "parent", BoneInfo__get_parent, BoneInfo__set_parent);
    return type;
}
static py_Type tp_user_BoneInfo;
static bool Model__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Model));
    return true;
}
static bool Model__init__(int argc, py_Ref argv) {
    Model* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Model));
    } else if(argc == 1 + 9) {
        do {
            if(!py_checktype(py_arg(1), tp_user_Matrix)) return false;
            self->transform = *(Matrix*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->meshCount = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->materialCount = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->meshes = (Mesh *)py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->materials = (Material *)py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->meshMaterial = (int *)py_toint(py_arg(6));
        if(!py_checkint(py_arg(7))) return false;
        self->boneCount = py_toint(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->bones = (BoneInfo *)py_toint(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->bindPose = (Transform *)py_toint(py_arg(9));
    } else {
        return TypeError("expected 1 or 10 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Model__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    Model* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Model));
    *res = *self;
    return true;
}
static bool Model__get_transform(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    do {
        Matrix* ud = py_newobject(py_retval(), tp_user_Matrix, 0, sizeof(Matrix));
        *ud = self->transform;
    } while(0);
    return true;
}
static bool Model__set_transform(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_Matrix)) return false;
        self->transform = *(Matrix*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Model__get_meshCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), self->meshCount);
    return true;
}
static bool Model__set_meshCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->meshCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_materialCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), self->materialCount);
    return true;
}
static bool Model__set_materialCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->materialCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_meshes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->meshes);
    return true;
}
static bool Model__set_meshes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->meshes = (Mesh *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_materials(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->materials);
    return true;
}
static bool Model__set_materials(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->materials = (Material *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_meshMaterial(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->meshMaterial);
    return true;
}
static bool Model__set_meshMaterial(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->meshMaterial = (int *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), self->boneCount);
    return true;
}
static bool Model__set_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_bones(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->bones);
    return true;
}
static bool Model__set_bones(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->bones = (BoneInfo *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Model__get_bindPose(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->bindPose);
    return true;
}
static bool Model__set_bindPose(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->bindPose = (Transform *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Model(py_GlobalRef mod) {
    py_Type type = py_newtype("Model", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Model__new__);
    py_bindmagic(type, __init__, Model__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Model__copy__);
    py_bindproperty(type, "transform", Model__get_transform, Model__set_transform);
    py_bindproperty(type, "meshCount", Model__get_meshCount, Model__set_meshCount);
    py_bindproperty(type, "materialCount", Model__get_materialCount, Model__set_materialCount);
    py_bindproperty(type, "meshes", Model__get_meshes, Model__set_meshes);
    py_bindproperty(type, "materials", Model__get_materials, Model__set_materials);
    py_bindproperty(type, "meshMaterial", Model__get_meshMaterial, Model__set_meshMaterial);
    py_bindproperty(type, "boneCount", Model__get_boneCount, Model__set_boneCount);
    py_bindproperty(type, "bones", Model__get_bones, Model__set_bones);
    py_bindproperty(type, "bindPose", Model__get_bindPose, Model__set_bindPose);
    return type;
}
static py_Type tp_user_Model;
static bool ModelAnimation__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(ModelAnimation));
    return true;
}
static bool ModelAnimation__init__(int argc, py_Ref argv) {
    ModelAnimation* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(ModelAnimation));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->boneCount = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->frameCount = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->bones = (BoneInfo *)py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->framePoses = (Transform **)py_toint(py_arg(4));
        // _4 name is read-only
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool ModelAnimation__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    ModelAnimation* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(ModelAnimation));
    *res = *self;
    return true;
}
static bool ModelAnimation__get_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    py_newint(py_retval(), self->boneCount);
    return true;
}
static bool ModelAnimation__set_boneCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    ModelAnimation* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->boneCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool ModelAnimation__get_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    py_newint(py_retval(), self->frameCount);
    return true;
}
static bool ModelAnimation__set_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    ModelAnimation* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->frameCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool ModelAnimation__get_bones(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->bones);
    return true;
}
static bool ModelAnimation__set_bones(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    ModelAnimation* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->bones = (BoneInfo *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool ModelAnimation__get_framePoses(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->framePoses);
    return true;
}
static bool ModelAnimation__set_framePoses(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    ModelAnimation* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->framePoses = (Transform **)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool ModelAnimation__get_name(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->name);
    return true;
}
static py_Type register__ModelAnimation(py_GlobalRef mod) {
    py_Type type = py_newtype("ModelAnimation", tp_object, mod, NULL);
    py_bindmagic(type, __new__, ModelAnimation__new__);
    py_bindmagic(type, __init__, ModelAnimation__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", ModelAnimation__copy__);
    py_bindproperty(type, "boneCount", ModelAnimation__get_boneCount, ModelAnimation__set_boneCount);
    py_bindproperty(type, "frameCount", ModelAnimation__get_frameCount, ModelAnimation__set_frameCount);
    py_bindproperty(type, "bones", ModelAnimation__get_bones, ModelAnimation__set_bones);
    py_bindproperty(type, "framePoses", ModelAnimation__get_framePoses, ModelAnimation__set_framePoses);
    py_bindproperty(type, "name", ModelAnimation__get_name, NULL);
    return type;
}
static py_Type tp_user_ModelAnimation;
static bool Ray__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Ray));
    return true;
}
static bool Ray__init__(int argc, py_Ref argv) {
    Ray* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Ray));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(1));
            self->position = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(2));
            self->direction = *(Vector3*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Ray__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Ray* self = py_touserdata(argv);
    Ray* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Ray));
    *res = *self;
    return true;
}
static bool Ray__get_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Ray* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->position));
    return true;
}
static bool Ray__set_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Ray* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->position = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Ray__get_direction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Ray* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->direction));
    return true;
}
static bool Ray__set_direction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Ray* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->direction = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__Ray(py_GlobalRef mod) {
    py_Type type = py_newtype("Ray", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Ray__new__);
    py_bindmagic(type, __init__, Ray__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Ray__copy__);
    py_bindproperty(type, "position", Ray__get_position, Ray__set_position);
    py_bindproperty(type, "direction", Ray__get_direction, Ray__set_direction);
    return type;
}
static py_Type tp_user_Ray;
static bool RayCollision__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(RayCollision));
    return true;
}
static bool RayCollision__init__(int argc, py_Ref argv) {
    RayCollision* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(RayCollision));
    } else if(argc == 1 + 4) {
        if(!py_checkbool(py_arg(1))) return false;
        self->hit = py_tobool(py_arg(1));
        if(!py_castfloat32(py_arg(2), &self->distance)) return false;
        do {
            if(!py_checktype(py_arg(3), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(3));
            self->point = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(4));
            self->normal = *(Vector3*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool RayCollision__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RayCollision* self = py_touserdata(argv);
    RayCollision* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(RayCollision));
    *res = *self;
    return true;
}
static bool RayCollision__get_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RayCollision* self = py_touserdata(argv);
    py_newbool(py_retval(), self->hit);
    return true;
}
static bool RayCollision__set_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RayCollision* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->hit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool RayCollision__get_distance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RayCollision* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->distance);
    return true;
}
static bool RayCollision__set_distance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RayCollision* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->distance)) return false;
    py_newnone(py_retval());
    return true;
}
static bool RayCollision__get_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RayCollision* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->point));
    return true;
}
static bool RayCollision__set_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RayCollision* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->point = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool RayCollision__get_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RayCollision* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->normal));
    return true;
}
static bool RayCollision__set_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    RayCollision* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->normal = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__RayCollision(py_GlobalRef mod) {
    py_Type type = py_newtype("RayCollision", tp_object, mod, NULL);
    py_bindmagic(type, __new__, RayCollision__new__);
    py_bindmagic(type, __init__, RayCollision__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", RayCollision__copy__);
    py_bindproperty(type, "hit", RayCollision__get_hit, RayCollision__set_hit);
    py_bindproperty(type, "distance", RayCollision__get_distance, RayCollision__set_distance);
    py_bindproperty(type, "point", RayCollision__get_point, RayCollision__set_point);
    py_bindproperty(type, "normal", RayCollision__get_normal, RayCollision__set_normal);
    return type;
}
static py_Type tp_user_RayCollision;
static bool BoundingBox__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(BoundingBox));
    return true;
}
static bool BoundingBox__init__(int argc, py_Ref argv) {
    BoundingBox* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(BoundingBox));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(1));
            self->min = *(Vector3*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec3)) return false;
            c11_vec3 tmp = py_tovec3(py_arg(2));
            self->max = *(Vector3*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool BoundingBox__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoundingBox* self = py_touserdata(argv);
    BoundingBox* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(BoundingBox));
    *res = *self;
    return true;
}
static bool BoundingBox__get_min(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoundingBox* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->min));
    return true;
}
static bool BoundingBox__set_min(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    BoundingBox* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->min = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool BoundingBox__get_max(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    BoundingBox* self = py_touserdata(argv);
    py_newvec3(py_retval(), *(c11_vec3*)(&self->max));
    return true;
}
static bool BoundingBox__set_max(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    BoundingBox* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        self->max = *(Vector3*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__BoundingBox(py_GlobalRef mod) {
    py_Type type = py_newtype("BoundingBox", tp_object, mod, NULL);
    py_bindmagic(type, __new__, BoundingBox__new__);
    py_bindmagic(type, __init__, BoundingBox__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", BoundingBox__copy__);
    py_bindproperty(type, "min", BoundingBox__get_min, BoundingBox__set_min);
    py_bindproperty(type, "max", BoundingBox__get_max, BoundingBox__set_max);
    return type;
}
static py_Type tp_user_BoundingBox;
static bool Wave__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Wave));
    return true;
}
static bool Wave__init__(int argc, py_Ref argv) {
    Wave* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Wave));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->frameCount = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->sampleRate = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->sampleSize = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->channels = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->data = (void *)py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Wave__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    Wave* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Wave));
    *res = *self;
    return true;
}
static bool Wave__get_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    py_newint(py_retval(), self->frameCount);
    return true;
}
static bool Wave__set_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->frameCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Wave__get_sampleRate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    py_newint(py_retval(), self->sampleRate);
    return true;
}
static bool Wave__set_sampleRate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->sampleRate = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Wave__get_sampleSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    py_newint(py_retval(), self->sampleSize);
    return true;
}
static bool Wave__set_sampleSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->sampleSize = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Wave__get_channels(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    py_newint(py_retval(), self->channels);
    return true;
}
static bool Wave__set_channels(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->channels = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Wave__get_data(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->data);
    return true;
}
static bool Wave__set_data(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->data = (void *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Wave(py_GlobalRef mod) {
    py_Type type = py_newtype("Wave", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Wave__new__);
    py_bindmagic(type, __init__, Wave__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Wave__copy__);
    py_bindproperty(type, "frameCount", Wave__get_frameCount, Wave__set_frameCount);
    py_bindproperty(type, "sampleRate", Wave__get_sampleRate, Wave__set_sampleRate);
    py_bindproperty(type, "sampleSize", Wave__get_sampleSize, Wave__set_sampleSize);
    py_bindproperty(type, "channels", Wave__get_channels, Wave__set_channels);
    py_bindproperty(type, "data", Wave__get_data, Wave__set_data);
    return type;
}
static py_Type tp_user_Wave;
static bool AudioStream__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(AudioStream));
    return true;
}
static bool AudioStream__init__(int argc, py_Ref argv) {
    AudioStream* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(AudioStream));
    } else if(argc == 1 + 5) {
        if(!py_checkint(py_arg(1))) return false;
        self->buffer = (rAudioBuffer *)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->processor = (rAudioProcessor *)py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->sampleRate = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->sampleSize = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->channels = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool AudioStream__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    AudioStream* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(AudioStream));
    *res = *self;
    return true;
}
static bool AudioStream__get_buffer(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->buffer);
    return true;
}
static bool AudioStream__set_buffer(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->buffer = (rAudioBuffer *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AudioStream__get_processor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->processor);
    return true;
}
static bool AudioStream__set_processor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->processor = (rAudioProcessor *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AudioStream__get_sampleRate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    py_newint(py_retval(), self->sampleRate);
    return true;
}
static bool AudioStream__set_sampleRate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->sampleRate = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AudioStream__get_sampleSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    py_newint(py_retval(), self->sampleSize);
    return true;
}
static bool AudioStream__set_sampleSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->sampleSize = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AudioStream__get_channels(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream* self = py_touserdata(argv);
    py_newint(py_retval(), self->channels);
    return true;
}
static bool AudioStream__set_channels(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->channels = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__AudioStream(py_GlobalRef mod) {
    py_Type type = py_newtype("AudioStream", tp_object, mod, NULL);
    py_bindmagic(type, __new__, AudioStream__new__);
    py_bindmagic(type, __init__, AudioStream__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", AudioStream__copy__);
    py_bindproperty(type, "buffer", AudioStream__get_buffer, AudioStream__set_buffer);
    py_bindproperty(type, "processor", AudioStream__get_processor, AudioStream__set_processor);
    py_bindproperty(type, "sampleRate", AudioStream__get_sampleRate, AudioStream__set_sampleRate);
    py_bindproperty(type, "sampleSize", AudioStream__get_sampleSize, AudioStream__set_sampleSize);
    py_bindproperty(type, "channels", AudioStream__get_channels, AudioStream__set_channels);
    return type;
}
static py_Type tp_user_AudioStream;
static bool Sound__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Sound));
    return true;
}
static bool Sound__init__(int argc, py_Ref argv) {
    Sound* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Sound));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_user_AudioStream)) return false;
            self->stream = *(AudioStream*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->frameCount = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Sound__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound* self = py_touserdata(argv);
    Sound* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Sound));
    *res = *self;
    return true;
}
static bool Sound__get_stream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound* self = py_touserdata(argv);
    do {
        AudioStream* ud = py_newobject(py_retval(), tp_user_AudioStream, 0, sizeof(AudioStream));
        *ud = self->stream;
    } while(0);
    return true;
}
static bool Sound__set_stream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Sound* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_AudioStream)) return false;
        self->stream = *(AudioStream*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Sound__get_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound* self = py_touserdata(argv);
    py_newint(py_retval(), self->frameCount);
    return true;
}
static bool Sound__set_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Sound* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->frameCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Sound(py_GlobalRef mod) {
    py_Type type = py_newtype("Sound", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Sound__new__);
    py_bindmagic(type, __init__, Sound__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Sound__copy__);
    py_bindproperty(type, "stream", Sound__get_stream, Sound__set_stream);
    py_bindproperty(type, "frameCount", Sound__get_frameCount, Sound__set_frameCount);
    return type;
}
static py_Type tp_user_Sound;
static bool Music__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(Music));
    return true;
}
static bool Music__init__(int argc, py_Ref argv) {
    Music* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(Music));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_user_AudioStream)) return false;
            self->stream = *(AudioStream*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->frameCount = py_toint(py_arg(2));
        if(!py_checkbool(py_arg(3))) return false;
        self->looping = py_tobool(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->ctxType = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->ctxData = (void *)py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool Music__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    Music* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(Music));
    *res = *self;
    return true;
}
static bool Music__get_stream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    do {
        AudioStream* ud = py_newobject(py_retval(), tp_user_AudioStream, 0, sizeof(AudioStream));
        *ud = self->stream;
    } while(0);
    return true;
}
static bool Music__set_stream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_AudioStream)) return false;
        self->stream = *(AudioStream*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool Music__get_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    py_newint(py_retval(), self->frameCount);
    return true;
}
static bool Music__set_frameCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->frameCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Music__get_looping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    py_newbool(py_retval(), self->looping);
    return true;
}
static bool Music__set_looping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->looping = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Music__get_ctxType(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    py_newint(py_retval(), self->ctxType);
    return true;
}
static bool Music__set_ctxType(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->ctxType = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool Music__get_ctxData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->ctxData);
    return true;
}
static bool Music__set_ctxData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->ctxData = (void *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__Music(py_GlobalRef mod) {
    py_Type type = py_newtype("Music", tp_object, mod, NULL);
    py_bindmagic(type, __new__, Music__new__);
    py_bindmagic(type, __init__, Music__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", Music__copy__);
    py_bindproperty(type, "stream", Music__get_stream, Music__set_stream);
    py_bindproperty(type, "frameCount", Music__get_frameCount, Music__set_frameCount);
    py_bindproperty(type, "looping", Music__get_looping, Music__set_looping);
    py_bindproperty(type, "ctxType", Music__get_ctxType, Music__set_ctxType);
    py_bindproperty(type, "ctxData", Music__get_ctxData, Music__set_ctxData);
    return type;
}
static py_Type tp_user_Music;
static bool VrDeviceInfo__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(VrDeviceInfo));
    return true;
}
static bool VrDeviceInfo__init__(int argc, py_Ref argv) {
    VrDeviceInfo* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(VrDeviceInfo));
    } else if(argc == 1 + 9) {
        if(!py_checkint(py_arg(1))) return false;
        self->hResolution = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->vResolution = py_toint(py_arg(2));
        if(!py_castfloat32(py_arg(3), &self->hScreenSize)) return false;
        if(!py_castfloat32(py_arg(4), &self->vScreenSize)) return false;
        if(!py_castfloat32(py_arg(5), &self->eyeToScreenDistance)) return false;
        if(!py_castfloat32(py_arg(6), &self->lensSeparationDistance)) return false;
        if(!py_castfloat32(py_arg(7), &self->interpupillaryDistance)) return false;
        // _7 lensDistortionValues is read-only
        // _8 chromaAbCorrection is read-only
    } else {
        return TypeError("expected 1 or 10 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    VrDeviceInfo* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(VrDeviceInfo));
    *res = *self;
    return true;
}
static bool VrDeviceInfo__get_hResolution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->hResolution);
    return true;
}
static bool VrDeviceInfo__set_hResolution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->hResolution = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_vResolution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newint(py_retval(), self->vResolution);
    return true;
}
static bool VrDeviceInfo__set_vResolution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->vResolution = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_hScreenSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hScreenSize);
    return true;
}
static bool VrDeviceInfo__set_hScreenSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hScreenSize)) return false;
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_vScreenSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->vScreenSize);
    return true;
}
static bool VrDeviceInfo__set_vScreenSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->vScreenSize)) return false;
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_eyeToScreenDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->eyeToScreenDistance);
    return true;
}
static bool VrDeviceInfo__set_eyeToScreenDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->eyeToScreenDistance)) return false;
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_lensSeparationDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->lensSeparationDistance);
    return true;
}
static bool VrDeviceInfo__set_lensSeparationDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->lensSeparationDistance)) return false;
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_interpupillaryDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->interpupillaryDistance);
    return true;
}
static bool VrDeviceInfo__set_interpupillaryDistance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    VrDeviceInfo* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->interpupillaryDistance)) return false;
    py_newnone(py_retval());
    return true;
}
static bool VrDeviceInfo__get_lensDistortionValues(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->lensDistortionValues);
    return true;
}
static bool VrDeviceInfo__get_chromaAbCorrection(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->chromaAbCorrection);
    return true;
}
static py_Type register__VrDeviceInfo(py_GlobalRef mod) {
    py_Type type = py_newtype("VrDeviceInfo", tp_object, mod, NULL);
    py_bindmagic(type, __new__, VrDeviceInfo__new__);
    py_bindmagic(type, __init__, VrDeviceInfo__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", VrDeviceInfo__copy__);
    py_bindproperty(type, "hResolution", VrDeviceInfo__get_hResolution, VrDeviceInfo__set_hResolution);
    py_bindproperty(type, "vResolution", VrDeviceInfo__get_vResolution, VrDeviceInfo__set_vResolution);
    py_bindproperty(type, "hScreenSize", VrDeviceInfo__get_hScreenSize, VrDeviceInfo__set_hScreenSize);
    py_bindproperty(type, "vScreenSize", VrDeviceInfo__get_vScreenSize, VrDeviceInfo__set_vScreenSize);
    py_bindproperty(type, "eyeToScreenDistance", VrDeviceInfo__get_eyeToScreenDistance, VrDeviceInfo__set_eyeToScreenDistance);
    py_bindproperty(type, "lensSeparationDistance", VrDeviceInfo__get_lensSeparationDistance, VrDeviceInfo__set_lensSeparationDistance);
    py_bindproperty(type, "interpupillaryDistance", VrDeviceInfo__get_interpupillaryDistance, VrDeviceInfo__set_interpupillaryDistance);
    py_bindproperty(type, "lensDistortionValues", VrDeviceInfo__get_lensDistortionValues, NULL);
    py_bindproperty(type, "chromaAbCorrection", VrDeviceInfo__get_chromaAbCorrection, NULL);
    return type;
}
static py_Type tp_user_VrDeviceInfo;
static bool VrStereoConfig__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(VrStereoConfig));
    return true;
}
static bool VrStereoConfig__init__(int argc, py_Ref argv) {
    VrStereoConfig* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(VrStereoConfig));
    } else if(argc == 1 + 8) {
        // _0 projection is read-only
        // _1 viewOffset is read-only
        // _2 leftLensCenter is read-only
        // _3 rightLensCenter is read-only
        // _4 leftScreenCenter is read-only
        // _5 rightScreenCenter is read-only
        // _6 scale is read-only
        // _7 scaleIn is read-only
    } else {
        return TypeError("expected 1 or 9 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool VrStereoConfig__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    VrStereoConfig* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(VrStereoConfig));
    *res = *self;
    return true;
}
static bool VrStereoConfig__get_projection(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->projection);
    return true;
}
static bool VrStereoConfig__get_viewOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->viewOffset);
    return true;
}
static bool VrStereoConfig__get_leftLensCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->leftLensCenter);
    return true;
}
static bool VrStereoConfig__get_rightLensCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->rightLensCenter);
    return true;
}
static bool VrStereoConfig__get_leftScreenCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->leftScreenCenter);
    return true;
}
static bool VrStereoConfig__get_rightScreenCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->rightScreenCenter);
    return true;
}
static bool VrStereoConfig__get_scale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->scale);
    return true;
}
static bool VrStereoConfig__get_scaleIn(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->scaleIn);
    return true;
}
static py_Type register__VrStereoConfig(py_GlobalRef mod) {
    py_Type type = py_newtype("VrStereoConfig", tp_object, mod, NULL);
    py_bindmagic(type, __new__, VrStereoConfig__new__);
    py_bindmagic(type, __init__, VrStereoConfig__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", VrStereoConfig__copy__);
    py_bindproperty(type, "projection", VrStereoConfig__get_projection, NULL);
    py_bindproperty(type, "viewOffset", VrStereoConfig__get_viewOffset, NULL);
    py_bindproperty(type, "leftLensCenter", VrStereoConfig__get_leftLensCenter, NULL);
    py_bindproperty(type, "rightLensCenter", VrStereoConfig__get_rightLensCenter, NULL);
    py_bindproperty(type, "leftScreenCenter", VrStereoConfig__get_leftScreenCenter, NULL);
    py_bindproperty(type, "rightScreenCenter", VrStereoConfig__get_rightScreenCenter, NULL);
    py_bindproperty(type, "scale", VrStereoConfig__get_scale, NULL);
    py_bindproperty(type, "scaleIn", VrStereoConfig__get_scaleIn, NULL);
    return type;
}
static py_Type tp_user_VrStereoConfig;
static bool FilePathList__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(FilePathList));
    return true;
}
static bool FilePathList__init__(int argc, py_Ref argv) {
    FilePathList* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(FilePathList));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->capacity = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->count = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->paths = (char **)py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool FilePathList__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList* self = py_touserdata(argv);
    FilePathList* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(FilePathList));
    *res = *self;
    return true;
}
static bool FilePathList__get_capacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList* self = py_touserdata(argv);
    py_newint(py_retval(), self->capacity);
    return true;
}
static bool FilePathList__set_capacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    FilePathList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->capacity = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool FilePathList__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool FilePathList__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    FilePathList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool FilePathList__get_paths(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->paths);
    return true;
}
static bool FilePathList__set_paths(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    FilePathList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->paths = (char **)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__FilePathList(py_GlobalRef mod) {
    py_Type type = py_newtype("FilePathList", tp_object, mod, NULL);
    py_bindmagic(type, __new__, FilePathList__new__);
    py_bindmagic(type, __init__, FilePathList__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", FilePathList__copy__);
    py_bindproperty(type, "capacity", FilePathList__get_capacity, FilePathList__set_capacity);
    py_bindproperty(type, "count", FilePathList__get_count, FilePathList__set_count);
    py_bindproperty(type, "paths", FilePathList__get_paths, FilePathList__set_paths);
    return type;
}
static py_Type tp_user_FilePathList;
static bool AutomationEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(AutomationEvent));
    return true;
}
static bool AutomationEvent__init__(int argc, py_Ref argv) {
    AutomationEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(AutomationEvent));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->frame = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->type = py_toint(py_arg(2));
        // _2 params is read-only
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool AutomationEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEvent* self = py_touserdata(argv);
    AutomationEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(AutomationEvent));
    *res = *self;
    return true;
}
static bool AutomationEvent__get_frame(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEvent* self = py_touserdata(argv);
    py_newint(py_retval(), self->frame);
    return true;
}
static bool AutomationEvent__set_frame(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEvent* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->frame = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AutomationEvent__get_type(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEvent* self = py_touserdata(argv);
    py_newint(py_retval(), self->type);
    return true;
}
static bool AutomationEvent__set_type(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEvent* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->type = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AutomationEvent__get_params(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEvent* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->params);
    return true;
}
static py_Type register__AutomationEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("AutomationEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, AutomationEvent__new__);
    py_bindmagic(type, __init__, AutomationEvent__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", AutomationEvent__copy__);
    py_bindproperty(type, "frame", AutomationEvent__get_frame, AutomationEvent__set_frame);
    py_bindproperty(type, "type", AutomationEvent__get_type, AutomationEvent__set_type);
    py_bindproperty(type, "params", AutomationEvent__get_params, NULL);
    return type;
}
static py_Type tp_user_AutomationEvent;
static bool AutomationEventList__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(AutomationEventList));
    return true;
}
static bool AutomationEventList__init__(int argc, py_Ref argv) {
    AutomationEventList* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(AutomationEventList));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->capacity = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->count = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->events = (AutomationEvent *)py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool AutomationEventList__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList* self = py_touserdata(argv);
    AutomationEventList* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(AutomationEventList));
    *res = *self;
    return true;
}
static bool AutomationEventList__get_capacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList* self = py_touserdata(argv);
    py_newint(py_retval(), self->capacity);
    return true;
}
static bool AutomationEventList__set_capacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEventList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->capacity = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AutomationEventList__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool AutomationEventList__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEventList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool AutomationEventList__get_events(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->events);
    return true;
}
static bool AutomationEventList__set_events(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEventList* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->events = (AutomationEvent *)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__AutomationEventList(py_GlobalRef mod) {
    py_Type type = py_newtype("AutomationEventList", tp_object, mod, NULL);
    py_bindmagic(type, __new__, AutomationEventList__new__);
    py_bindmagic(type, __init__, AutomationEventList__init__);
    py_bindmethod(type, "__address__", struct__address__);
    py_bindmethod(type, "copy", AutomationEventList__copy__);
    py_bindproperty(type, "capacity", AutomationEventList__get_capacity, AutomationEventList__set_capacity);
    py_bindproperty(type, "count", AutomationEventList__get_count, AutomationEventList__set_count);
    py_bindproperty(type, "events", AutomationEventList__get_events, AutomationEventList__set_events);
    return type;
}
static py_Type tp_user_AutomationEventList;
/* functions */
static bool cfunc__InitWindow(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    InitWindow(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__CloseWindow(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    CloseWindow();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__WindowShouldClose(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = WindowShouldClose();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowReady(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowReady();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowFullscreen(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowFullscreen();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowHidden(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowHidden();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowMinimized(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowMinimized();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowMaximized(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowMaximized();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowFocused(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowFocused();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowResized(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsWindowResized();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsWindowState(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsWindowState(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__SetWindowState(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetWindowState(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ClearWindowState(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    ClearWindowState(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ToggleFullscreen(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    ToggleFullscreen();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ToggleBorderlessWindowed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    ToggleBorderlessWindowed();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__MaximizeWindow(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    MaximizeWindow();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__MinimizeWindow(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    MinimizeWindow();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__RestoreWindow(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    RestoreWindow();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowIcon(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    SetWindowIcon(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowIcons(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetWindowIcons(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowTitle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    SetWindowTitle(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowPosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetWindowPosition(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowMonitor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetWindowMonitor(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowMinSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetWindowMinSize(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowMaxSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetWindowMaxSize(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetWindowSize(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowOpacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    SetWindowOpacity(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetWindowFocused(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    SetWindowFocused();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetWindowHandle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    void * res = GetWindowHandle();
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__GetScreenWidth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetScreenWidth();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetScreenHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetScreenHeight();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetRenderWidth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetRenderWidth();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetRenderHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetRenderHeight();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetMonitorCount();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetCurrentMonitor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetCurrentMonitor();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorPosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    Vector2 res = GetMonitorPosition(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetMonitorWidth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetMonitorWidth(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetMonitorHeight(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorPhysicalWidth(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetMonitorPhysicalWidth(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorPhysicalHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetMonitorPhysicalHeight(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMonitorRefreshRate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetMonitorRefreshRate(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetWindowPosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetWindowPosition();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetWindowScaleDPI(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetWindowScaleDPI();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetMonitorName(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    const char * res = GetMonitorName(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__SetClipboardText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    SetClipboardText(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetClipboardText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    const char * res = GetClipboardText();
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__EnableEventWaiting(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EnableEventWaiting();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DisableEventWaiting(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    DisableEventWaiting();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ShowCursor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    ShowCursor();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__HideCursor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    HideCursor();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsCursorHidden(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsCursorHidden();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__EnableCursor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EnableCursor();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DisableCursor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    DisableCursor();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsCursorOnScreen(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsCursorOnScreen();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__ClearBackground(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    ClearBackground(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginDrawing(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    BeginDrawing();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndDrawing(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndDrawing();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginMode2D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera2D)) return false;
        _0 = *(Camera2D*)py_touserdata(py_arg(0));
    } while(0);
    BeginMode2D(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndMode2D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndMode2D();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginMode3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera3D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera3D)) return false;
        _0 = *(Camera3D*)py_touserdata(py_arg(0));
    } while(0);
    BeginMode3D(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndMode3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndMode3D();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginTextureMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_RenderTexture2D)) return false;
        _0 = *(RenderTexture2D*)py_touserdata(py_arg(0));
    } while(0);
    BeginTextureMode(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndTextureMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndTextureMode();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginShaderMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    BeginShaderMode(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndShaderMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndShaderMode();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginBlendMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    BeginBlendMode(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndBlendMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndBlendMode();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginScissorMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    BeginScissorMode(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndScissorMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndScissorMode();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__BeginVrStereoMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_VrStereoConfig)) return false;
        _0 = *(VrStereoConfig*)py_touserdata(py_arg(0));
    } while(0);
    BeginVrStereoMode(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__EndVrStereoMode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    EndVrStereoMode();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadVrStereoConfig(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrDeviceInfo _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_VrDeviceInfo)) return false;
        _0 = *(VrDeviceInfo*)py_touserdata(py_arg(0));
    } while(0);
    VrStereoConfig res = LoadVrStereoConfig(_0);
    do {
        VrStereoConfig* ud = py_newobject(py_retval(), tp_user_VrStereoConfig, 0, sizeof(VrStereoConfig));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__UnloadVrStereoConfig(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    VrStereoConfig _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_VrStereoConfig)) return false;
        _0 = *(VrStereoConfig*)py_touserdata(py_arg(0));
    } while(0);
    UnloadVrStereoConfig(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadShader(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    Shader res = LoadShader(_0, _1);
    do {
        Shader* ud = py_newobject(py_retval(), tp_user_Shader, 0, sizeof(Shader));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadShaderFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    Shader res = LoadShaderFromMemory(_0, _1);
    do {
        Shader* ud = py_newobject(py_retval(), tp_user_Shader, 0, sizeof(Shader));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsShaderValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsShaderValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetShaderLocation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int res = GetShaderLocation(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetShaderLocationAttrib(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int res = GetShaderLocationAttrib(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__SetShaderValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const void * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const void *)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    SetShaderValue(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetShaderValueV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const void * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const void *)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    SetShaderValueV(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetShaderValueMatrix(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Matrix _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Matrix)) return false;
        _2 = *(Matrix*)py_touserdata(py_arg(2));
    } while(0);
    SetShaderValueMatrix(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetShaderValueTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Texture2D _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Texture2D)) return false;
        _2 = *(Texture2D*)py_touserdata(py_arg(2));
    } while(0);
    SetShaderValueTexture(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadShader(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Shader _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Shader)) return false;
        _0 = *(Shader*)py_touserdata(py_arg(0));
    } while(0);
    UnloadShader(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetScreenToWorldRay(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Camera _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera)) return false;
        _1 = *(Camera*)py_touserdata(py_arg(1));
    } while(0);
    Ray res = GetScreenToWorldRay(_0, _1);
    do {
        Ray* ud = py_newobject(py_retval(), tp_user_Ray, 0, sizeof(Ray));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetScreenToWorldRayEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Camera _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera)) return false;
        _1 = *(Camera*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Ray res = GetScreenToWorldRayEx(_0, _1, _2, _3);
    do {
        Ray* ud = py_newobject(py_retval(), tp_user_Ray, 0, sizeof(Ray));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetWorldToScreen(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Camera _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera)) return false;
        _1 = *(Camera*)py_touserdata(py_arg(1));
    } while(0);
    Vector2 res = GetWorldToScreen(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetWorldToScreenEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Camera _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera)) return false;
        _1 = *(Camera*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Vector2 res = GetWorldToScreenEx(_0, _1, _2, _3);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetWorldToScreen2D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Camera2D _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera2D)) return false;
        _1 = *(Camera2D*)py_touserdata(py_arg(1));
    } while(0);
    Vector2 res = GetWorldToScreen2D(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetScreenToWorld2D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Camera2D _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Camera2D)) return false;
        _1 = *(Camera2D*)py_touserdata(py_arg(1));
    } while(0);
    Vector2 res = GetScreenToWorld2D(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetCameraMatrix(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera)) return false;
        _0 = *(Camera*)py_touserdata(py_arg(0));
    } while(0);
    Matrix res = GetCameraMatrix(_0);
    do {
        Matrix* ud = py_newobject(py_retval(), tp_user_Matrix, 0, sizeof(Matrix));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetCameraMatrix2D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Camera2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera2D)) return false;
        _0 = *(Camera2D*)py_touserdata(py_arg(0));
    } while(0);
    Matrix res = GetCameraMatrix2D(_0);
    do {
        Matrix* ud = py_newobject(py_retval(), tp_user_Matrix, 0, sizeof(Matrix));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__SetTargetFPS(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetTargetFPS(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetFrameTime(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetFrameTime();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetTime(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    double res = GetTime();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetFPS(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetFPS();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__SwapScreenBuffer(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    SwapScreenBuffer();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PollInputEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    PollInputEvents();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__WaitTime(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    double _0;
    if(!py_castfloat(py_arg(0), &_0)) return false;
    WaitTime(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetRandomSeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetRandomSeed(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetRandomValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int res = GetRandomValue(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__LoadRandomSequence(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int * res = LoadRandomSequence(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadRandomSequence(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (int *)py_toint(py_arg(0));
    UnloadRandomSequence(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__TakeScreenshot(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    TakeScreenshot(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetConfigFlags(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetConfigFlags(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__OpenURL(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    OpenURL(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetTraceLogLevel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetTraceLogLevel(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__MemAlloc(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    void * res = MemAlloc(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__MemRealloc(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    void * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (void *)py_toint(py_arg(0));
    unsigned int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    void * res = MemRealloc(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__MemFree(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    void * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (void *)py_toint(py_arg(0));
    MemFree(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadFileData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    unsigned char * res = LoadFileData(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadFileData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (unsigned char *)py_toint(py_arg(0));
    UnloadFileData(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SaveFileData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    void * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (void *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    bool res = SaveFileData(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__ExportDataAsCode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    bool res = ExportDataAsCode(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__LoadFileText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    char * res = LoadFileText(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadFileText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (char *)py_toint(py_arg(0));
    UnloadFileText(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SaveFileText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (char *)py_toint(py_arg(1));
    bool res = SaveFileText(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__FileExists(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    bool res = FileExists(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__DirectoryExists(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    bool res = DirectoryExists(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsFileExtension(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = IsFileExtension(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetFileLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int res = GetFileLength(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetFileExtension(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = GetFileExtension(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetFileName(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = GetFileName(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetFileNameWithoutExt(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = GetFileNameWithoutExt(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetDirectoryPath(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = GetDirectoryPath(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetPrevDirectoryPath(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = GetPrevDirectoryPath(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetWorkingDirectory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    const char * res = GetWorkingDirectory();
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__GetApplicationDirectory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    const char * res = GetApplicationDirectory();
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__MakeDirectory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int res = MakeDirectory(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__ChangeDirectory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    bool res = ChangeDirectory(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsPathFile(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    bool res = IsPathFile(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsFileNameValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    bool res = IsFileNameValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__LoadDirectoryFiles(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    FilePathList res = LoadDirectoryFiles(_0);
    do {
        FilePathList* ud = py_newobject(py_retval(), tp_user_FilePathList, 0, sizeof(FilePathList));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadDirectoryFilesEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    FilePathList res = LoadDirectoryFilesEx(_0, _1, _2);
    do {
        FilePathList* ud = py_newobject(py_retval(), tp_user_FilePathList, 0, sizeof(FilePathList));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__UnloadDirectoryFiles(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_FilePathList)) return false;
        _0 = *(FilePathList*)py_touserdata(py_arg(0));
    } while(0);
    UnloadDirectoryFiles(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsFileDropped(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsFileDropped();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__LoadDroppedFiles(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    FilePathList res = LoadDroppedFiles();
    do {
        FilePathList* ud = py_newobject(py_retval(), tp_user_FilePathList, 0, sizeof(FilePathList));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__UnloadDroppedFiles(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    FilePathList _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_FilePathList)) return false;
        _0 = *(FilePathList*)py_touserdata(py_arg(0));
    } while(0);
    UnloadDroppedFiles(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetFileModTime(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    long res = GetFileModTime(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__CompressData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    unsigned char * res = CompressData(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__DecompressData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    unsigned char * res = DecompressData(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__EncodeDataBase64(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    char * res = EncodeDataBase64(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__DecodeDataBase64(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    unsigned char * res = DecodeDataBase64(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__ComputeCRC32(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    unsigned int res = ComputeCRC32(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__ComputeMD5(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    unsigned int * res = ComputeMD5(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__ComputeSHA1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    unsigned int * res = ComputeSHA1(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__LoadAutomationEventList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    AutomationEventList res = LoadAutomationEventList(_0);
    do {
        AutomationEventList* ud = py_newobject(py_retval(), tp_user_AutomationEventList, 0, sizeof(AutomationEventList));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__UnloadAutomationEventList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AutomationEventList)) return false;
        _0 = *(AutomationEventList*)py_touserdata(py_arg(0));
    } while(0);
    UnloadAutomationEventList(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ExportAutomationEventList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AutomationEventList _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AutomationEventList)) return false;
        _0 = *(AutomationEventList*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportAutomationEventList(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__SetAutomationEventList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEventList * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (AutomationEventList *)py_toint(py_arg(0));
    SetAutomationEventList(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetAutomationEventBaseFrame(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetAutomationEventBaseFrame(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__StartAutomationEventRecording(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    StartAutomationEventRecording();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__StopAutomationEventRecording(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    StopAutomationEventRecording();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PlayAutomationEvent(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AutomationEvent _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AutomationEvent)) return false;
        _0 = *(AutomationEvent*)py_touserdata(py_arg(0));
    } while(0);
    PlayAutomationEvent(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsKeyPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsKeyPressed(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsKeyPressedRepeat(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsKeyPressedRepeat(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsKeyDown(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsKeyDown(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsKeyReleased(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsKeyReleased(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsKeyUp(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsKeyUp(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetKeyPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetKeyPressed();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetCharPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetCharPressed();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__SetExitKey(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetExitKey(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsGamepadAvailable(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsGamepadAvailable(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetGamepadName(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    const char * res = GetGamepadName(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__IsGamepadButtonPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    bool res = IsGamepadButtonPressed(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsGamepadButtonDown(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    bool res = IsGamepadButtonDown(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsGamepadButtonReleased(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    bool res = IsGamepadButtonReleased(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsGamepadButtonUp(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    bool res = IsGamepadButtonUp(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetGamepadButtonPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetGamepadButtonPressed();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetGamepadAxisCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetGamepadAxisCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetGamepadAxisMovement(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float res = GetGamepadAxisMovement(_0, _1);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__SetGamepadMappings(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int res = SetGamepadMappings(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__SetGamepadVibration(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    SetGamepadVibration(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsMouseButtonPressed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsMouseButtonPressed(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsMouseButtonDown(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsMouseButtonDown(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsMouseButtonReleased(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsMouseButtonReleased(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__IsMouseButtonUp(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsMouseButtonUp(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetMouseX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetMouseX();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMouseY(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetMouseY();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetMousePosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetMousePosition();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetMouseDelta(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetMouseDelta();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__SetMousePosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetMousePosition(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMouseOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetMouseOffset(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMouseScale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetMouseScale(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetMouseWheelMove(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetMouseWheelMove();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetMouseWheelMoveV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetMouseWheelMoveV();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__SetMouseCursor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetMouseCursor(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetTouchX(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetTouchX();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetTouchY(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetTouchY();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetTouchPosition(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    Vector2 res = GetTouchPosition(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetTouchPointId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int res = GetTouchPointId(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetTouchPointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetTouchPointCount();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__SetGesturesEnabled(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetGesturesEnabled(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsGestureDetected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    bool res = IsGestureDetected(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetGestureDetected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    int res = GetGestureDetected();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetGestureHoldDuration(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetGestureHoldDuration();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetGestureDragVector(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetGestureDragVector();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetGestureDragAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetGestureDragAngle();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetGesturePinchVector(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Vector2 res = GetGesturePinchVector();
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetGesturePinchAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetGesturePinchAngle();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__UpdateCamera(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Camera * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Camera *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    UpdateCamera(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateCameraPro(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Camera * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Camera *)py_toint(py_arg(0));
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    UpdateCameraPro(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetShapesTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    SetShapesTexture(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetShapesTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Texture2D res = GetShapesTexture();
    do {
        Texture2D* ud = py_newobject(py_retval(), tp_user_Texture2D, 0, sizeof(Texture2D));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetShapesTextureRectangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Rectangle res = GetShapesTextureRectangle();
    do {
        Rectangle* ud = py_newobject(py_retval(), tp_user_Rectangle, 0, sizeof(Rectangle));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__DrawPixel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawPixel(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPixelV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    DrawPixelV(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawLine(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawLine(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawLineV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawLineV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawLineEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawLineEx(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawLineStrip(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawLineStrip(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawLineBezier(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawLineBezier(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawCircle(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleSector(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCircleSector(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleSectorLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCircleSectorLines(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleGradient(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawCircleGradient(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawCircleV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawCircleLines(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircleLinesV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawCircleLinesV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawEllipse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawEllipse(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawEllipseLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawEllipseLines(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRing(int argc, py_Ref argv) {
    PY_CHECK_ARGC(7);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    int _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = py_toint(py_arg(5));
    Color _6;
    do {
        if(!py_checktype(py_arg(6), tp_user_Color)) return false;
        _6 = *(Color*)py_touserdata(py_arg(6));
    } while(0);
    DrawRing(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRingLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(7);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    int _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = py_toint(py_arg(5));
    Color _6;
    do {
        if(!py_checktype(py_arg(6), tp_user_Color)) return false;
        _6 = *(Color*)py_touserdata(py_arg(6));
    } while(0);
    DrawRingLines(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawRectangle(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawRectangleV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    DrawRectangleRec(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectanglePro(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawRectanglePro(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleGradientV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawRectangleGradientV(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleGradientH(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawRectangleGradientH(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleGradientEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawRectangleGradientEx(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawRectangleLines(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleLinesEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawRectangleLinesEx(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleRounded(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawRectangleRounded(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleRoundedLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawRectangleRoundedLines(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRectangleRoundedLinesEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawRectangleRoundedLinesEx(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawTriangle(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawTriangleLines(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangleFan(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawTriangleFan(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangleStrip(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawTriangleStrip(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPoly(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawPoly(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPolyLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawPolyLines(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPolyLinesEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawPolyLinesEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineLinear(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineLinear(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineBasis(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineBasis(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineCatmullRom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineCatmullRom(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineBezierQuadratic(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineBezierQuadratic(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineBezierCubic(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const Vector2 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector2 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineBezierCubic(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineSegmentLinear(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawSplineSegmentLinear(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineSegmentBasis(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawSplineSegmentBasis(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineSegmentCatmullRom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawSplineSegmentCatmullRom(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineSegmentBezierQuadratic(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawSplineSegmentBezierQuadratic(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSplineSegmentBezierCubic(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawSplineSegmentBezierCubic(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetSplinePointLinear(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Vector2 res = GetSplinePointLinear(_0, _1, _2);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetSplinePointBasis(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Vector2 res = GetSplinePointBasis(_0, _1, _2, _3, _4);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetSplinePointCatmullRom(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Vector2 res = GetSplinePointCatmullRom(_0, _1, _2, _3, _4);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetSplinePointBezierQuad(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Vector2 res = GetSplinePointBezierQuad(_0, _1, _2, _3);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetSplinePointBezierCubic(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Vector2 res = GetSplinePointBezierCubic(_0, _1, _2, _3, _4);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__CheckCollisionRecs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    bool res = CheckCollisionRecs(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionCircles(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    bool res = CheckCollisionCircles(_0, _1, _2, _3);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionCircleRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    bool res = CheckCollisionCircleRec(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionCircleLine(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    bool res = CheckCollisionCircleLine(_0, _1, _2, _3);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionPointRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    bool res = CheckCollisionPointRec(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionPointCircle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    bool res = CheckCollisionPointCircle(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionPointTriangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    bool res = CheckCollisionPointTriangle(_0, _1, _2, _3);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionPointLine(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    bool res = CheckCollisionPointLine(_0, _1, _2, _3);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionPointPoly(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    const Vector2 * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const Vector2 *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    bool res = CheckCollisionPointPoly(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 * _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (Vector2 *)py_toint(py_arg(4));
    bool res = CheckCollisionLines(_0, _1, _2, _3, _4);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetCollisionRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Rectangle _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Rectangle)) return false;
        _0 = *(Rectangle*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle res = GetCollisionRec(_0, _1);
    do {
        Rectangle* ud = py_newobject(py_retval(), tp_user_Rectangle, 0, sizeof(Rectangle));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Image res = LoadImage(_0);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageRaw(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Image res = LoadImageRaw(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageAnim(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    Image res = LoadImageAnim(_0, _1);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageAnimFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const unsigned char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const unsigned char *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int * _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (int *)py_toint(py_arg(3));
    Image res = LoadImageAnimFromMemory(_0, _1, _2, _3);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const unsigned char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const unsigned char *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Image res = LoadImageFromMemory(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageFromTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Image res = LoadImageFromTexture(_0);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadImageFromScreen(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Image res = LoadImageFromScreen();
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsImageValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsImageValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    UnloadImage(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ExportImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportImage(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__ExportImageToMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    unsigned char * res = ExportImageToMemory(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__ExportImageAsCode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportImageAsCode(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GenImageColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    Image res = GenImageColor(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageGradientLinear(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Image res = GenImageGradientLinear(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageGradientRadial(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Image res = GenImageGradientRadial(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageGradientSquare(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Image res = GenImageGradientSquare(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageChecked(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    Image res = GenImageChecked(_0, _1, _2, _3, _4, _5);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageWhiteNoise(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Image res = GenImageWhiteNoise(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImagePerlinNoise(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Image res = GenImagePerlinNoise(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageCellular(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Image res = GenImageCellular(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenImageText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    Image res = GenImageText(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageCopy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Image res = ImageCopy(_0);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageFromImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    Image res = ImageFromImage(_0, _1);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageFromChannel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Image res = ImageFromChannel(_0, _1);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    Image res = ImageText(_0, _1, _2);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageTextEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Image res = ImageTextEx(_0, _1, _2, _3, _4);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageFormat(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    ImageFormat(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageToPOT(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    ImageToPOT(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageCrop(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    ImageCrop(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageAlphaCrop(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    ImageAlphaCrop(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageAlphaClear(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    ImageAlphaClear(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageAlphaMask(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Image _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Image)) return false;
        _1 = *(Image*)py_touserdata(py_arg(1));
    } while(0);
    ImageAlphaMask(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageAlphaPremultiply(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageAlphaPremultiply(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageBlurGaussian(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    ImageBlurGaussian(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageKernelConvolution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    const float * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const float *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    ImageKernelConvolution(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageResize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    ImageResize(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageResizeNN(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    ImageResizeNN(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageResizeCanvas(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    ImageResizeCanvas(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageMipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageMipmaps(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDither(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    ImageDither(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageFlipVertical(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageFlipVertical(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageFlipHorizontal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageFlipHorizontal(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageRotate(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    ImageRotate(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageRotateCW(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageRotateCW(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageRotateCCW(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageRotateCCW(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorTint(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    ImageColorTint(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorInvert(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageColorInvert(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorGrayscale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    ImageColorGrayscale(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorContrast(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    ImageColorContrast(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorBrightness(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    ImageColorBrightness(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageColorReplace(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    ImageColorReplace(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadImageColors(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Color * res = LoadImageColors(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__LoadImagePalette(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    Color * res = LoadImagePalette(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadImageColors(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Color *)py_toint(py_arg(0));
    UnloadImageColors(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadImagePalette(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Color *)py_toint(py_arg(0));
    UnloadImagePalette(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetImageAlphaBorder(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Rectangle res = GetImageAlphaBorder(_0, _1);
    do {
        Rectangle* ud = py_newobject(py_retval(), tp_user_Rectangle, 0, sizeof(Rectangle));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetImageColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color res = GetImageColor(_0, _1, _2);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ImageClearBackground(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    ImageClearBackground(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawPixel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawPixel(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawPixelV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    ImageDrawPixelV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawLine(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    ImageDrawLine(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawLineV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawLineV(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawLineEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDrawLineEx(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawCircle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDrawCircle(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawCircleV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawCircleV(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawCircleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDrawCircleLines(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawCircleLinesV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawCircleLinesV(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawRectangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    ImageDrawRectangle(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawRectangleV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawRectangleV(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawRectangleRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    ImageDrawRectangleRec(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawRectangleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawRectangleLines(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTriangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDrawTriangle(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTriangleEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(7);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    Color _6;
    do {
        if(!py_checktype(py_arg(6), tp_user_Color)) return false;
        _6 = *(Color*)py_touserdata(py_arg(6));
    } while(0);
    ImageDrawTriangleEx(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTriangleLines(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDrawTriangleLines(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTriangleFan(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (Vector2 *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawTriangleFan(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTriangleStrip(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Vector2 * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (Vector2 *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    ImageDrawTriangleStrip(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDraw(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Image _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Image)) return false;
        _1 = *(Image*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    Rectangle _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Rectangle)) return false;
        _3 = *(Rectangle*)py_touserdata(py_arg(3));
    } while(0);
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    ImageDraw(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    ImageDrawText(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ImageDrawTextEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(7);
    Image * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Image *)py_toint(py_arg(0));
    Font _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Font)) return false;
        _1 = *(Font*)py_touserdata(py_arg(1));
    } while(0);
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    float _5;
    if(!py_castfloat32(py_arg(5), &_5)) return false;
    Color _6;
    do {
        if(!py_checktype(py_arg(6), tp_user_Color)) return false;
        _6 = *(Color*)py_touserdata(py_arg(6));
    } while(0);
    ImageDrawTextEx(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Texture2D res = LoadTexture(_0);
    do {
        Texture2D* ud = py_newobject(py_retval(), tp_user_Texture2D, 0, sizeof(Texture2D));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadTextureFromImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Texture2D res = LoadTextureFromImage(_0);
    do {
        Texture2D* ud = py_newobject(py_retval(), tp_user_Texture2D, 0, sizeof(Texture2D));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadTextureCubemap(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    TextureCubemap res = LoadTextureCubemap(_0, _1);
    do {
        TextureCubemap* ud = py_newobject(py_retval(), tp_user_TextureCubemap, 0, sizeof(TextureCubemap));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadRenderTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    RenderTexture2D res = LoadRenderTexture(_0, _1);
    do {
        RenderTexture2D* ud = py_newobject(py_retval(), tp_user_RenderTexture2D, 0, sizeof(RenderTexture2D));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsTextureValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsTextureValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    UnloadTexture(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsRenderTextureValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_RenderTexture2D)) return false;
        _0 = *(RenderTexture2D*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsRenderTextureValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadRenderTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    RenderTexture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_RenderTexture2D)) return false;
        _0 = *(RenderTexture2D*)py_touserdata(py_arg(0));
    } while(0);
    UnloadRenderTexture(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    const void * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const void *)py_toint(py_arg(1));
    UpdateTexture(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateTextureRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    const void * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const void *)py_toint(py_arg(2));
    UpdateTextureRec(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GenTextureMipmaps(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Texture2D * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Texture2D *)py_toint(py_arg(0));
    GenTextureMipmaps(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetTextureFilter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetTextureFilter(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetTextureWrap(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    SetTextureWrap(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawTexture(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextureV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawTextureV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextureEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawTextureEx(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextureRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawTextureRec(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTexturePro(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    Rectangle _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Rectangle)) return false;
        _1 = *(Rectangle*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawTexturePro(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextureNPatch(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Texture2D _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Texture2D)) return false;
        _0 = *(Texture2D*)py_touserdata(py_arg(0));
    } while(0);
    NPatchInfo _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_NPatchInfo)) return false;
        _1 = *(NPatchInfo*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawTextureNPatch(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ColorIsEqual(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    bool res = ColorIsEqual(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__Fade(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color res = Fade(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorToInt(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    int res = ColorToInt(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__ColorNormalize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Vector4 res = ColorNormalize(_0);
    do {
        Vector4* ud = py_newobject(py_retval(), tp_user_Vector4, 0, sizeof(Vector4));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorFromNormalized(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Vector4 _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Vector4)) return false;
        _0 = *(Vector4*)py_touserdata(py_arg(0));
    } while(0);
    Color res = ColorFromNormalized(_0);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorToHSV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 res = ColorToHSV(_0);
    py_newvec3(py_retval(), *(c11_vec3*)(&res));
    return true;
}
static bool cfunc__ColorFromHSV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color res = ColorFromHSV(_0, _1, _2);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorTint(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    Color res = ColorTint(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorBrightness(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color res = ColorBrightness(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorContrast(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color res = ColorContrast(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorAlpha(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color res = ColorAlpha(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorAlphaBlend(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    Color res = ColorAlphaBlend(_0, _1, _2);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__ColorLerp(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Color _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Color)) return false;
        _0 = *(Color*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color res = ColorLerp(_0, _1, _2);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    Color res = GetColor(_0);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetPixelColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    void * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (void *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color res = GetPixelColor(_0, _1);
    do {
        Color* ud = py_newobject(py_retval(), tp_user_Color, 0, sizeof(Color));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__SetPixelColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    void * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (void *)py_toint(py_arg(0));
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    SetPixelColor(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetPixelDataSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int res = GetPixelDataSize(_0, _1, _2);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetFontDefault(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Font res = GetFontDefault();
    do {
        Font* ud = py_newobject(py_retval(), tp_user_Font, 0, sizeof(Font));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadFont(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Font res = LoadFont(_0);
    do {
        Font* ud = py_newobject(py_retval(), tp_user_Font, 0, sizeof(Font));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadFontEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Font res = LoadFontEx(_0, _1, _2, _3);
    do {
        Font* ud = py_newobject(py_retval(), tp_user_Font, 0, sizeof(Font));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadFontFromImage(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Font res = LoadFontFromImage(_0, _1, _2);
    do {
        Font* ud = py_newobject(py_retval(), tp_user_Font, 0, sizeof(Font));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadFontFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const unsigned char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const unsigned char *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int * _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (int *)py_toint(py_arg(4));
    int _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = py_toint(py_arg(5));
    Font res = LoadFontFromMemory(_0, _1, _2, _3, _4, _5);
    do {
        Font* ud = py_newobject(py_retval(), tp_user_Font, 0, sizeof(Font));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsFontValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsFontValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__LoadFontData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    const unsigned char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const unsigned char *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int * _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (int *)py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    int _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = py_toint(py_arg(5));
    GlyphInfo * res = LoadFontData(_0, _1, _2, _3, _4, _5);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__GenImageFontAtlas(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    const GlyphInfo * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const GlyphInfo *)py_toint(py_arg(0));
    Rectangle ** _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (Rectangle **)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    int _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = py_toint(py_arg(5));
    Image res = GenImageFontAtlas(_0, _1, _2, _3, _4, _5);
    do {
        Image* ud = py_newobject(py_retval(), tp_user_Image, 0, sizeof(Image));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__UnloadFontData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    GlyphInfo * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (GlyphInfo *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    UnloadFontData(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadFont(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    UnloadFont(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ExportFontAsCode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportFontAsCode(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__DrawFPS(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    DrawFPS(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawText(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawTextEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextPro(int argc, py_Ref argv) {
    PY_CHECK_ARGC(8);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    float _5;
    if(!py_castfloat32(py_arg(5), &_5)) return false;
    float _6;
    if(!py_castfloat32(py_arg(6), &_6)) return false;
    Color _7;
    do {
        if(!py_checktype(py_arg(7), tp_user_Color)) return false;
        _7 = *(Color*)py_touserdata(py_arg(7));
    } while(0);
    DrawTextPro(_0, _1, _2, _3, _4, _5, _6, _7);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextCodepoint(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Vector2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(Vector2*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawTextCodepoint(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTextCodepoints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(7);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const int *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Vector2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(Vector2*)(&tmp);
    } while(0);
    float _4;
    if(!py_castfloat32(py_arg(4), &_4)) return false;
    float _5;
    if(!py_castfloat32(py_arg(5), &_5)) return false;
    Color _6;
    do {
        if(!py_checktype(py_arg(6), tp_user_Color)) return false;
        _6 = *(Color*)py_touserdata(py_arg(6));
    } while(0);
    DrawTextCodepoints(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetTextLineSpacing(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetTextLineSpacing(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__MeasureText(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int res = MeasureText(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__MeasureTextEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Vector2 res = MeasureTextEx(_0, _1, _2, _3);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__GetGlyphIndex(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int res = GetGlyphIndex(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetGlyphInfo(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    GlyphInfo res = GetGlyphInfo(_0, _1);
    do {
        GlyphInfo* ud = py_newobject(py_retval(), tp_user_GlyphInfo, 0, sizeof(GlyphInfo));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetGlyphAtlasRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Font _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Font)) return false;
        _0 = *(Font*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Rectangle res = GetGlyphAtlasRec(_0, _1);
    do {
        Rectangle* ud = py_newobject(py_retval(), tp_user_Rectangle, 0, sizeof(Rectangle));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadUTF8(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const int * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const int *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    char * res = LoadUTF8(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadUTF8(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (char *)py_toint(py_arg(0));
    UnloadUTF8(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadCodepoints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    int * res = LoadCodepoints(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadCodepoints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (int *)py_toint(py_arg(0));
    UnloadCodepoints(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetCodepointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int res = GetCodepointCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetCodepoint(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    int res = GetCodepoint(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetCodepointNext(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    int res = GetCodepointNext(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__GetCodepointPrevious(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    int res = GetCodepointPrevious(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__CodepointToUTF8(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    const char * res = CodepointToUTF8(_0, _1);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextCopy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (char *)py_toint(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int res = TextCopy(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__TextIsEqual(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = TextIsEqual(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__TextLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    unsigned int res = TextLength(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__TextSubtext(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    const char * res = TextSubtext(_0, _1, _2);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextReplace(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    char * res = TextReplace(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__TextInsert(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    char * res = TextInsert(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__TextJoin(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char ** _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const char **)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const char * _2;
    if(!py_checkstr(py_arg(2))) return false;
    _2 = py_tostr(py_arg(2));
    const char * res = TextJoin(_0, _1, _2);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextSplit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    char _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    const char ** res = TextSplit(_0, _1, _2);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__TextAppend(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    char * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (char *)py_toint(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (int *)py_toint(py_arg(2));
    TextAppend(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__TextFindIndex(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    int res = TextFindIndex(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__TextToUpper(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = TextToUpper(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextToLower(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = TextToLower(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextToPascal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = TextToPascal(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextToSnake(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = TextToSnake(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextToCamel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const char * res = TextToCamel(_0);
    py_newstr(py_retval(), res);
    return true;
}
static bool cfunc__TextToInteger(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int res = TextToInteger(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__TextToFloat(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    float res = TextToFloat(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__DrawLine3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawLine3D(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPoint3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    DrawPoint3D(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCircle3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawCircle3D(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangle3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawTriangle3D(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawTriangleStrip3D(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const Vector3 * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const Vector3 *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawTriangleStrip3D(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCube(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawCube(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCubeV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawCubeV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCubeWires(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawCubeWires(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCubeWiresV(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawCubeWiresV(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSphere(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawSphere(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSphereEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawSphereEx(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawSphereWires(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawSphereWires(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCylinder(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCylinder(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCylinderEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCylinderEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCylinderWires(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCylinderWires(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCylinderWiresEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCylinderWiresEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCapsule(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCapsule(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawCapsuleWires(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawCapsuleWires(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawPlane(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    Vector2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(Vector2*)(&tmp);
    } while(0);
    Color _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Color)) return false;
        _2 = *(Color*)py_touserdata(py_arg(2));
    } while(0);
    DrawPlane(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawRay(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    DrawRay(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawGrid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    DrawGrid(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadModel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Model res = LoadModel(_0);
    do {
        Model* ud = py_newobject(py_retval(), tp_user_Model, 0, sizeof(Model));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadModelFromMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    Model res = LoadModelFromMesh(_0);
    do {
        Model* ud = py_newobject(py_retval(), tp_user_Model, 0, sizeof(Model));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsModelValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsModelValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadModel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    UnloadModel(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetModelBoundingBox(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    BoundingBox res = GetModelBoundingBox(_0);
    do {
        BoundingBox* ud = py_newobject(py_retval(), tp_user_BoundingBox, 0, sizeof(BoundingBox));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__DrawModel(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawModel(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawModelEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Vector3 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(4));
        _4 = *(Vector3*)(&tmp);
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawModelEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawModelWires(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawModelWires(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawModelWiresEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Vector3 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(4));
        _4 = *(Vector3*)(&tmp);
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawModelWiresEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawModelPoints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Color _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_Color)) return false;
        _3 = *(Color*)py_touserdata(py_arg(3));
    } while(0);
    DrawModelPoints(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawModelPointsEx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Vector3 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(4));
        _4 = *(Vector3*)(&tmp);
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawModelPointsEx(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawBoundingBox(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    BoundingBox _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_BoundingBox)) return false;
        _0 = *(BoundingBox*)py_touserdata(py_arg(0));
    } while(0);
    Color _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Color)) return false;
        _1 = *(Color*)py_touserdata(py_arg(1));
    } while(0);
    DrawBoundingBox(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawBillboard(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Camera _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera)) return false;
        _0 = *(Camera*)py_touserdata(py_arg(0));
    } while(0);
    Texture2D _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
        _1 = *(Texture2D*)py_touserdata(py_arg(1));
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    Color _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_Color)) return false;
        _4 = *(Color*)py_touserdata(py_arg(4));
    } while(0);
    DrawBillboard(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawBillboardRec(int argc, py_Ref argv) {
    PY_CHECK_ARGC(6);
    Camera _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera)) return false;
        _0 = *(Camera*)py_touserdata(py_arg(0));
    } while(0);
    Texture2D _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
        _1 = *(Texture2D*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    Vector3 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(3));
        _3 = *(Vector3*)(&tmp);
    } while(0);
    Vector2 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(4));
        _4 = *(Vector2*)(&tmp);
    } while(0);
    Color _5;
    do {
        if(!py_checktype(py_arg(5), tp_user_Color)) return false;
        _5 = *(Color*)py_touserdata(py_arg(5));
    } while(0);
    DrawBillboardRec(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawBillboardPro(int argc, py_Ref argv) {
    PY_CHECK_ARGC(9);
    Camera _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Camera)) return false;
        _0 = *(Camera*)py_touserdata(py_arg(0));
    } while(0);
    Texture2D _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Texture2D)) return false;
        _1 = *(Texture2D*)py_touserdata(py_arg(1));
    } while(0);
    Rectangle _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Rectangle)) return false;
        _2 = *(Rectangle*)py_touserdata(py_arg(2));
    } while(0);
    Vector3 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(3));
        _3 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(4));
        _4 = *(Vector3*)(&tmp);
    } while(0);
    Vector2 _5;
    do {
        if(!py_checktype(py_arg(5), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(5));
        _5 = *(Vector2*)(&tmp);
    } while(0);
    Vector2 _6;
    do {
        if(!py_checktype(py_arg(6), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(6));
        _6 = *(Vector2*)(&tmp);
    } while(0);
    float _7;
    if(!py_castfloat32(py_arg(7), &_7)) return false;
    Color _8;
    do {
        if(!py_checktype(py_arg(8), tp_user_Color)) return false;
        _8 = *(Color*)py_touserdata(py_arg(8));
    } while(0);
    DrawBillboardPro(_0, _1, _2, _3, _4, _5, _6, _7, _8);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UploadMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Mesh *)py_toint(py_arg(0));
    bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    UploadMesh(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateMeshBuffer(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    const void * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const void *)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = py_toint(py_arg(4));
    UpdateMeshBuffer(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    UnloadMesh(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    Material _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Material)) return false;
        _1 = *(Material*)py_touserdata(py_arg(1));
    } while(0);
    Matrix _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Matrix)) return false;
        _2 = *(Matrix*)py_touserdata(py_arg(2));
    } while(0);
    DrawMesh(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__DrawMeshInstanced(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    Material _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Material)) return false;
        _1 = *(Material*)py_touserdata(py_arg(1));
    } while(0);
    const Matrix * _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const Matrix *)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    DrawMeshInstanced(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetMeshBoundingBox(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    BoundingBox res = GetMeshBoundingBox(_0);
    do {
        BoundingBox* ud = py_newobject(py_retval(), tp_user_BoundingBox, 0, sizeof(BoundingBox));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshTangents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Mesh * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Mesh *)py_toint(py_arg(0));
    GenMeshTangents(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ExportMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportMesh(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__ExportMeshAsCode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Mesh _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Mesh)) return false;
        _0 = *(Mesh*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportMeshAsCode(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GenMeshPoly(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Mesh res = GenMeshPoly(_0, _1);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshPlane(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Mesh res = GenMeshPlane(_0, _1, _2, _3);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshCube(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    Mesh res = GenMeshCube(_0, _1, _2);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshSphere(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Mesh res = GenMeshSphere(_0, _1, _2);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshHemiSphere(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Mesh res = GenMeshHemiSphere(_0, _1, _2);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshCylinder(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Mesh res = GenMeshCylinder(_0, _1, _2);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshCone(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Mesh res = GenMeshCone(_0, _1, _2);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshTorus(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Mesh res = GenMeshTorus(_0, _1, _2, _3);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshKnot(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    Mesh res = GenMeshKnot(_0, _1, _2, _3);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshHeightmap(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Mesh res = GenMeshHeightmap(_0, _1);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GenMeshCubicmap(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Image _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Image)) return false;
        _0 = *(Image*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Mesh res = GenMeshCubicmap(_0, _1);
    do {
        Mesh* ud = py_newobject(py_retval(), tp_user_Mesh, 0, sizeof(Mesh));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadMaterials(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    Material * res = LoadMaterials(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__LoadMaterialDefault(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    Material res = LoadMaterialDefault();
    do {
        Material* ud = py_newobject(py_retval(), tp_user_Material, 0, sizeof(Material));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsMaterialValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Material)) return false;
        _0 = *(Material*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsMaterialValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadMaterial(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Material _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Material)) return false;
        _0 = *(Material*)py_touserdata(py_arg(0));
    } while(0);
    UnloadMaterial(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMaterialTexture(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Material * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Material *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    Texture2D _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Texture2D)) return false;
        _2 = *(Texture2D*)py_touserdata(py_arg(2));
    } while(0);
    SetMaterialTexture(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetModelMeshMaterial(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Model * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Model *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    SetModelMeshMaterial(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadModelAnimations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    int * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (int *)py_toint(py_arg(1));
    ModelAnimation * res = LoadModelAnimations(_0, _1);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UpdateModelAnimation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    ModelAnimation _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_ModelAnimation)) return false;
        _1 = *(ModelAnimation*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    UpdateModelAnimation(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateModelAnimationBones(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    ModelAnimation _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_ModelAnimation)) return false;
        _1 = *(ModelAnimation*)py_touserdata(py_arg(1));
    } while(0);
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    UpdateModelAnimationBones(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadModelAnimation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    ModelAnimation _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_ModelAnimation)) return false;
        _0 = *(ModelAnimation*)py_touserdata(py_arg(0));
    } while(0);
    UnloadModelAnimation(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadModelAnimations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    ModelAnimation * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (ModelAnimation *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    UnloadModelAnimations(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsModelAnimationValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Model _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Model)) return false;
        _0 = *(Model*)py_touserdata(py_arg(0));
    } while(0);
    ModelAnimation _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_ModelAnimation)) return false;
        _1 = *(ModelAnimation*)py_touserdata(py_arg(1));
    } while(0);
    bool res = IsModelAnimationValid(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionSpheres(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Vector3 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(0));
        _0 = *(Vector3*)(&tmp);
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    bool res = CheckCollisionSpheres(_0, _1, _2, _3);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionBoxes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    BoundingBox _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_BoundingBox)) return false;
        _0 = *(BoundingBox*)py_touserdata(py_arg(0));
    } while(0);
    BoundingBox _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_BoundingBox)) return false;
        _1 = *(BoundingBox*)py_touserdata(py_arg(1));
    } while(0);
    bool res = CheckCollisionBoxes(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__CheckCollisionBoxSphere(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    BoundingBox _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_BoundingBox)) return false;
        _0 = *(BoundingBox*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    bool res = CheckCollisionBoxSphere(_0, _1, _2);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__GetRayCollisionSphere(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    RayCollision res = GetRayCollisionSphere(_0, _1, _2);
    do {
        RayCollision* ud = py_newobject(py_retval(), tp_user_RayCollision, 0, sizeof(RayCollision));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetRayCollisionBox(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    BoundingBox _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_BoundingBox)) return false;
        _1 = *(BoundingBox*)py_touserdata(py_arg(1));
    } while(0);
    RayCollision res = GetRayCollisionBox(_0, _1);
    do {
        RayCollision* ud = py_newobject(py_retval(), tp_user_RayCollision, 0, sizeof(RayCollision));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetRayCollisionMesh(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    Mesh _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_Mesh)) return false;
        _1 = *(Mesh*)py_touserdata(py_arg(1));
    } while(0);
    Matrix _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_Matrix)) return false;
        _2 = *(Matrix*)py_touserdata(py_arg(2));
    } while(0);
    RayCollision res = GetRayCollisionMesh(_0, _1, _2);
    do {
        RayCollision* ud = py_newobject(py_retval(), tp_user_RayCollision, 0, sizeof(RayCollision));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetRayCollisionTriangle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(3));
        _3 = *(Vector3*)(&tmp);
    } while(0);
    RayCollision res = GetRayCollisionTriangle(_0, _1, _2, _3);
    do {
        RayCollision* ud = py_newobject(py_retval(), tp_user_RayCollision, 0, sizeof(RayCollision));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__GetRayCollisionQuad(int argc, py_Ref argv) {
    PY_CHECK_ARGC(5);
    Ray _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Ray)) return false;
        _0 = *(Ray*)py_touserdata(py_arg(0));
    } while(0);
    Vector3 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(1));
        _1 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(2));
        _2 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(3));
        _3 = *(Vector3*)(&tmp);
    } while(0);
    Vector3 _4;
    do {
        if(!py_checktype(py_arg(4), tp_vec3)) return false;
        c11_vec3 tmp = py_tovec3(py_arg(4));
        _4 = *(Vector3*)(&tmp);
    } while(0);
    RayCollision res = GetRayCollisionQuad(_0, _1, _2, _3, _4);
    do {
        RayCollision* ud = py_newobject(py_retval(), tp_user_RayCollision, 0, sizeof(RayCollision));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__InitAudioDevice(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    InitAudioDevice();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__CloseAudioDevice(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    CloseAudioDevice();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsAudioDeviceReady(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    bool res = IsAudioDeviceReady();
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__SetMasterVolume(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    SetMasterVolume(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetMasterVolume(int argc, py_Ref argv) {
    PY_CHECK_ARGC(0);
    float res = GetMasterVolume();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__LoadWave(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Wave res = LoadWave(_0);
    do {
        Wave* ud = py_newobject(py_retval(), tp_user_Wave, 0, sizeof(Wave));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadWaveFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const unsigned char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const unsigned char *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Wave res = LoadWaveFromMemory(_0, _1, _2);
    do {
        Wave* ud = py_newobject(py_retval(), tp_user_Wave, 0, sizeof(Wave));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsWaveValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsWaveValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__LoadSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Sound res = LoadSound(_0);
    do {
        Sound* ud = py_newobject(py_retval(), tp_user_Sound, 0, sizeof(Sound));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadSoundFromWave(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    Sound res = LoadSoundFromWave(_0);
    do {
        Sound* ud = py_newobject(py_retval(), tp_user_Sound, 0, sizeof(Sound));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadSoundAlias(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    Sound res = LoadSoundAlias(_0);
    do {
        Sound* ud = py_newobject(py_retval(), tp_user_Sound, 0, sizeof(Sound));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsSoundValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsSoundValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UpdateSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    const void * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const void *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    UpdateSound(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadWave(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    UnloadWave(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    UnloadSound(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UnloadSoundAlias(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    UnloadSoundAlias(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ExportWave(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportWave(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__ExportWaveAsCode(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    const char * _1;
    if(!py_checkstr(py_arg(1))) return false;
    _1 = py_tostr(py_arg(1));
    bool res = ExportWaveAsCode(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__PlaySound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    PlaySound(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__StopSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    StopSound(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PauseSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    PauseSound(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ResumeSound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    ResumeSound(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsSoundPlaying(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsSoundPlaying(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__SetSoundVolume(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetSoundVolume(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetSoundPitch(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetSoundPitch(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetSoundPan(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Sound _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Sound)) return false;
        _0 = *(Sound*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetSoundPan(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__WaveCopy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    Wave res = WaveCopy(_0);
    do {
        Wave* ud = py_newobject(py_retval(), tp_user_Wave, 0, sizeof(Wave));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__WaveCrop(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    Wave * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Wave *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    WaveCrop(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__WaveFormat(int argc, py_Ref argv) {
    PY_CHECK_ARGC(4);
    Wave * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (Wave *)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    WaveFormat(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadWaveSamples(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Wave _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Wave)) return false;
        _0 = *(Wave*)py_touserdata(py_arg(0));
    } while(0);
    float * res = LoadWaveSamples(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__UnloadWaveSamples(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    float * _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (float *)py_toint(py_arg(0));
    UnloadWaveSamples(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__LoadMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    Music res = LoadMusicStream(_0);
    do {
        Music* ud = py_newobject(py_retval(), tp_user_Music, 0, sizeof(Music));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__LoadMusicStreamFromMemory(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    const char * _0;
    if(!py_checkstr(py_arg(0))) return false;
    _0 = py_tostr(py_arg(0));
    const unsigned char * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const unsigned char *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    Music res = LoadMusicStreamFromMemory(_0, _1, _2);
    do {
        Music* ud = py_newobject(py_retval(), tp_user_Music, 0, sizeof(Music));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsMusicValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsMusicValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    UnloadMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PlayMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    PlayMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsMusicStreamPlaying(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsMusicStreamPlaying(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UpdateMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    UpdateMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__StopMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    StopMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PauseMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    PauseMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ResumeMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    ResumeMusicStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SeekMusicStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SeekMusicStream(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMusicVolume(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetMusicVolume(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMusicPitch(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetMusicPitch(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetMusicPan(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetMusicPan(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__GetMusicTimeLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float res = GetMusicTimeLength(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__GetMusicTimePlayed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    Music _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_Music)) return false;
        _0 = *(Music*)py_touserdata(py_arg(0));
    } while(0);
    float res = GetMusicTimePlayed(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__LoadAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    unsigned int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    unsigned int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    unsigned int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    AudioStream res = LoadAudioStream(_0, _1, _2);
    do {
        AudioStream* ud = py_newobject(py_retval(), tp_user_AudioStream, 0, sizeof(AudioStream));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__IsAudioStreamValid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsAudioStreamValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__UnloadAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    UnloadAudioStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__UpdateAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(3);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    const void * _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const void *)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    UpdateAudioStream(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsAudioStreamProcessed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsAudioStreamProcessed(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__PlayAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    PlayAudioStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__PauseAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    PauseAudioStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__ResumeAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    ResumeAudioStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__IsAudioStreamPlaying(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    bool res = IsAudioStreamPlaying(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__StopAudioStream(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    StopAudioStream(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetAudioStreamVolume(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetAudioStreamVolume(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetAudioStreamPitch(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetAudioStreamPitch(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetAudioStreamPan(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    AudioStream _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_AudioStream)) return false;
        _0 = *(AudioStream*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    SetAudioStreamPan(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__SetAudioStreamBufferSizeDefault(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    SetAudioStreamBufferSizeDefault(_0);
    py_newnone(py_retval());
    return true;
}
void py__add_module_raylib() {
    py_GlobalRef mod = py_newmodule("raylib");
    /* structs */
    tp_user_Vector2 = register__Vector2(mod);
    tp_user_Vector3 = register__Vector3(mod);
    tp_user_Vector4 = register__Vector4(mod);
    tp_user_Matrix = register__Matrix(mod);
    tp_user_Color = register__Color(mod);
    tp_user_Rectangle = register__Rectangle(mod);
    tp_user_Image = register__Image(mod);
    tp_user_Texture = register__Texture(mod);
    tp_user_RenderTexture = register__RenderTexture(mod);
    tp_user_NPatchInfo = register__NPatchInfo(mod);
    tp_user_GlyphInfo = register__GlyphInfo(mod);
    tp_user_Font = register__Font(mod);
    tp_user_Camera3D = register__Camera3D(mod);
    tp_user_Camera2D = register__Camera2D(mod);
    tp_user_Mesh = register__Mesh(mod);
    tp_user_Shader = register__Shader(mod);
    tp_user_MaterialMap = register__MaterialMap(mod);
    tp_user_Material = register__Material(mod);
    tp_user_Transform = register__Transform(mod);
    tp_user_BoneInfo = register__BoneInfo(mod);
    tp_user_Model = register__Model(mod);
    tp_user_ModelAnimation = register__ModelAnimation(mod);
    tp_user_Ray = register__Ray(mod);
    tp_user_RayCollision = register__RayCollision(mod);
    tp_user_BoundingBox = register__BoundingBox(mod);
    tp_user_Wave = register__Wave(mod);
    tp_user_AudioStream = register__AudioStream(mod);
    tp_user_Sound = register__Sound(mod);
    tp_user_Music = register__Music(mod);
    tp_user_VrDeviceInfo = register__VrDeviceInfo(mod);
    tp_user_VrStereoConfig = register__VrStereoConfig(mod);
    tp_user_FilePathList = register__FilePathList(mod);
    tp_user_AutomationEvent = register__AutomationEvent(mod);
    tp_user_AutomationEventList = register__AutomationEventList(mod);
    /* aliases */
    py_setdict(mod, py_name("Quaternion"), py_getdict(mod, py_name("Vector4")));
    py_setdict(mod, py_name("Texture2D"), py_getdict(mod, py_name("Texture")));
    py_setdict(mod, py_name("TextureCubemap"), py_getdict(mod, py_name("Texture")));
    py_setdict(mod, py_name("RenderTexture2D"), py_getdict(mod, py_name("RenderTexture")));
    py_setdict(mod, py_name("Camera"), py_getdict(mod, py_name("Camera3D")));
    /* functions */
    py_bindfunc(mod, "InitWindow", &cfunc__InitWindow);
    py_bindfunc(mod, "CloseWindow", &cfunc__CloseWindow);
    py_bindfunc(mod, "WindowShouldClose", &cfunc__WindowShouldClose);
    py_bindfunc(mod, "IsWindowReady", &cfunc__IsWindowReady);
    py_bindfunc(mod, "IsWindowFullscreen", &cfunc__IsWindowFullscreen);
    py_bindfunc(mod, "IsWindowHidden", &cfunc__IsWindowHidden);
    py_bindfunc(mod, "IsWindowMinimized", &cfunc__IsWindowMinimized);
    py_bindfunc(mod, "IsWindowMaximized", &cfunc__IsWindowMaximized);
    py_bindfunc(mod, "IsWindowFocused", &cfunc__IsWindowFocused);
    py_bindfunc(mod, "IsWindowResized", &cfunc__IsWindowResized);
    py_bindfunc(mod, "IsWindowState", &cfunc__IsWindowState);
    py_bindfunc(mod, "SetWindowState", &cfunc__SetWindowState);
    py_bindfunc(mod, "ClearWindowState", &cfunc__ClearWindowState);
    py_bindfunc(mod, "ToggleFullscreen", &cfunc__ToggleFullscreen);
    py_bindfunc(mod, "ToggleBorderlessWindowed", &cfunc__ToggleBorderlessWindowed);
    py_bindfunc(mod, "MaximizeWindow", &cfunc__MaximizeWindow);
    py_bindfunc(mod, "MinimizeWindow", &cfunc__MinimizeWindow);
    py_bindfunc(mod, "RestoreWindow", &cfunc__RestoreWindow);
    py_bindfunc(mod, "SetWindowIcon", &cfunc__SetWindowIcon);
    py_bindfunc(mod, "SetWindowIcons", &cfunc__SetWindowIcons);
    py_bindfunc(mod, "SetWindowTitle", &cfunc__SetWindowTitle);
    py_bindfunc(mod, "SetWindowPosition", &cfunc__SetWindowPosition);
    py_bindfunc(mod, "SetWindowMonitor", &cfunc__SetWindowMonitor);
    py_bindfunc(mod, "SetWindowMinSize", &cfunc__SetWindowMinSize);
    py_bindfunc(mod, "SetWindowMaxSize", &cfunc__SetWindowMaxSize);
    py_bindfunc(mod, "SetWindowSize", &cfunc__SetWindowSize);
    py_bindfunc(mod, "SetWindowOpacity", &cfunc__SetWindowOpacity);
    py_bindfunc(mod, "SetWindowFocused", &cfunc__SetWindowFocused);
    py_bindfunc(mod, "GetWindowHandle", &cfunc__GetWindowHandle);
    py_bindfunc(mod, "GetScreenWidth", &cfunc__GetScreenWidth);
    py_bindfunc(mod, "GetScreenHeight", &cfunc__GetScreenHeight);
    py_bindfunc(mod, "GetRenderWidth", &cfunc__GetRenderWidth);
    py_bindfunc(mod, "GetRenderHeight", &cfunc__GetRenderHeight);
    py_bindfunc(mod, "GetMonitorCount", &cfunc__GetMonitorCount);
    py_bindfunc(mod, "GetCurrentMonitor", &cfunc__GetCurrentMonitor);
    py_bindfunc(mod, "GetMonitorPosition", &cfunc__GetMonitorPosition);
    py_bindfunc(mod, "GetMonitorWidth", &cfunc__GetMonitorWidth);
    py_bindfunc(mod, "GetMonitorHeight", &cfunc__GetMonitorHeight);
    py_bindfunc(mod, "GetMonitorPhysicalWidth", &cfunc__GetMonitorPhysicalWidth);
    py_bindfunc(mod, "GetMonitorPhysicalHeight", &cfunc__GetMonitorPhysicalHeight);
    py_bindfunc(mod, "GetMonitorRefreshRate", &cfunc__GetMonitorRefreshRate);
    py_bindfunc(mod, "GetWindowPosition", &cfunc__GetWindowPosition);
    py_bindfunc(mod, "GetWindowScaleDPI", &cfunc__GetWindowScaleDPI);
    py_bindfunc(mod, "GetMonitorName", &cfunc__GetMonitorName);
    py_bindfunc(mod, "SetClipboardText", &cfunc__SetClipboardText);
    py_bindfunc(mod, "GetClipboardText", &cfunc__GetClipboardText);
    py_bindfunc(mod, "EnableEventWaiting", &cfunc__EnableEventWaiting);
    py_bindfunc(mod, "DisableEventWaiting", &cfunc__DisableEventWaiting);
    py_bindfunc(mod, "ShowCursor", &cfunc__ShowCursor);
    py_bindfunc(mod, "HideCursor", &cfunc__HideCursor);
    py_bindfunc(mod, "IsCursorHidden", &cfunc__IsCursorHidden);
    py_bindfunc(mod, "EnableCursor", &cfunc__EnableCursor);
    py_bindfunc(mod, "DisableCursor", &cfunc__DisableCursor);
    py_bindfunc(mod, "IsCursorOnScreen", &cfunc__IsCursorOnScreen);
    py_bindfunc(mod, "ClearBackground", &cfunc__ClearBackground);
    py_bindfunc(mod, "BeginDrawing", &cfunc__BeginDrawing);
    py_bindfunc(mod, "EndDrawing", &cfunc__EndDrawing);
    py_bindfunc(mod, "BeginMode2D", &cfunc__BeginMode2D);
    py_bindfunc(mod, "EndMode2D", &cfunc__EndMode2D);
    py_bindfunc(mod, "BeginMode3D", &cfunc__BeginMode3D);
    py_bindfunc(mod, "EndMode3D", &cfunc__EndMode3D);
    py_bindfunc(mod, "BeginTextureMode", &cfunc__BeginTextureMode);
    py_bindfunc(mod, "EndTextureMode", &cfunc__EndTextureMode);
    py_bindfunc(mod, "BeginShaderMode", &cfunc__BeginShaderMode);
    py_bindfunc(mod, "EndShaderMode", &cfunc__EndShaderMode);
    py_bindfunc(mod, "BeginBlendMode", &cfunc__BeginBlendMode);
    py_bindfunc(mod, "EndBlendMode", &cfunc__EndBlendMode);
    py_bindfunc(mod, "BeginScissorMode", &cfunc__BeginScissorMode);
    py_bindfunc(mod, "EndScissorMode", &cfunc__EndScissorMode);
    py_bindfunc(mod, "BeginVrStereoMode", &cfunc__BeginVrStereoMode);
    py_bindfunc(mod, "EndVrStereoMode", &cfunc__EndVrStereoMode);
    py_bindfunc(mod, "LoadVrStereoConfig", &cfunc__LoadVrStereoConfig);
    py_bindfunc(mod, "UnloadVrStereoConfig", &cfunc__UnloadVrStereoConfig);
    py_bindfunc(mod, "LoadShader", &cfunc__LoadShader);
    py_bindfunc(mod, "LoadShaderFromMemory", &cfunc__LoadShaderFromMemory);
    py_bindfunc(mod, "IsShaderValid", &cfunc__IsShaderValid);
    py_bindfunc(mod, "GetShaderLocation", &cfunc__GetShaderLocation);
    py_bindfunc(mod, "GetShaderLocationAttrib", &cfunc__GetShaderLocationAttrib);
    py_bindfunc(mod, "SetShaderValue", &cfunc__SetShaderValue);
    py_bindfunc(mod, "SetShaderValueV", &cfunc__SetShaderValueV);
    py_bindfunc(mod, "SetShaderValueMatrix", &cfunc__SetShaderValueMatrix);
    py_bindfunc(mod, "SetShaderValueTexture", &cfunc__SetShaderValueTexture);
    py_bindfunc(mod, "UnloadShader", &cfunc__UnloadShader);
    py_bindfunc(mod, "GetScreenToWorldRay", &cfunc__GetScreenToWorldRay);
    py_bindfunc(mod, "GetScreenToWorldRayEx", &cfunc__GetScreenToWorldRayEx);
    py_bindfunc(mod, "GetWorldToScreen", &cfunc__GetWorldToScreen);
    py_bindfunc(mod, "GetWorldToScreenEx", &cfunc__GetWorldToScreenEx);
    py_bindfunc(mod, "GetWorldToScreen2D", &cfunc__GetWorldToScreen2D);
    py_bindfunc(mod, "GetScreenToWorld2D", &cfunc__GetScreenToWorld2D);
    py_bindfunc(mod, "GetCameraMatrix", &cfunc__GetCameraMatrix);
    py_bindfunc(mod, "GetCameraMatrix2D", &cfunc__GetCameraMatrix2D);
    py_bindfunc(mod, "SetTargetFPS", &cfunc__SetTargetFPS);
    py_bindfunc(mod, "GetFrameTime", &cfunc__GetFrameTime);
    py_bindfunc(mod, "GetTime", &cfunc__GetTime);
    py_bindfunc(mod, "GetFPS", &cfunc__GetFPS);
    py_bindfunc(mod, "SwapScreenBuffer", &cfunc__SwapScreenBuffer);
    py_bindfunc(mod, "PollInputEvents", &cfunc__PollInputEvents);
    py_bindfunc(mod, "WaitTime", &cfunc__WaitTime);
    py_bindfunc(mod, "SetRandomSeed", &cfunc__SetRandomSeed);
    py_bindfunc(mod, "GetRandomValue", &cfunc__GetRandomValue);
    py_bindfunc(mod, "LoadRandomSequence", &cfunc__LoadRandomSequence);
    py_bindfunc(mod, "UnloadRandomSequence", &cfunc__UnloadRandomSequence);
    py_bindfunc(mod, "TakeScreenshot", &cfunc__TakeScreenshot);
    py_bindfunc(mod, "SetConfigFlags", &cfunc__SetConfigFlags);
    py_bindfunc(mod, "OpenURL", &cfunc__OpenURL);
    py_bindfunc(mod, "SetTraceLogLevel", &cfunc__SetTraceLogLevel);
    py_bindfunc(mod, "MemAlloc", &cfunc__MemAlloc);
    py_bindfunc(mod, "MemRealloc", &cfunc__MemRealloc);
    py_bindfunc(mod, "MemFree", &cfunc__MemFree);
    py_bindfunc(mod, "LoadFileData", &cfunc__LoadFileData);
    py_bindfunc(mod, "UnloadFileData", &cfunc__UnloadFileData);
    py_bindfunc(mod, "SaveFileData", &cfunc__SaveFileData);
    py_bindfunc(mod, "ExportDataAsCode", &cfunc__ExportDataAsCode);
    py_bindfunc(mod, "LoadFileText", &cfunc__LoadFileText);
    py_bindfunc(mod, "UnloadFileText", &cfunc__UnloadFileText);
    py_bindfunc(mod, "SaveFileText", &cfunc__SaveFileText);
    py_bindfunc(mod, "FileExists", &cfunc__FileExists);
    py_bindfunc(mod, "DirectoryExists", &cfunc__DirectoryExists);
    py_bindfunc(mod, "IsFileExtension", &cfunc__IsFileExtension);
    py_bindfunc(mod, "GetFileLength", &cfunc__GetFileLength);
    py_bindfunc(mod, "GetFileExtension", &cfunc__GetFileExtension);
    py_bindfunc(mod, "GetFileName", &cfunc__GetFileName);
    py_bindfunc(mod, "GetFileNameWithoutExt", &cfunc__GetFileNameWithoutExt);
    py_bindfunc(mod, "GetDirectoryPath", &cfunc__GetDirectoryPath);
    py_bindfunc(mod, "GetPrevDirectoryPath", &cfunc__GetPrevDirectoryPath);
    py_bindfunc(mod, "GetWorkingDirectory", &cfunc__GetWorkingDirectory);
    py_bindfunc(mod, "GetApplicationDirectory", &cfunc__GetApplicationDirectory);
    py_bindfunc(mod, "MakeDirectory", &cfunc__MakeDirectory);
    py_bindfunc(mod, "ChangeDirectory", &cfunc__ChangeDirectory);
    py_bindfunc(mod, "IsPathFile", &cfunc__IsPathFile);
    py_bindfunc(mod, "IsFileNameValid", &cfunc__IsFileNameValid);
    py_bindfunc(mod, "LoadDirectoryFiles", &cfunc__LoadDirectoryFiles);
    py_bindfunc(mod, "LoadDirectoryFilesEx", &cfunc__LoadDirectoryFilesEx);
    py_bindfunc(mod, "UnloadDirectoryFiles", &cfunc__UnloadDirectoryFiles);
    py_bindfunc(mod, "IsFileDropped", &cfunc__IsFileDropped);
    py_bindfunc(mod, "LoadDroppedFiles", &cfunc__LoadDroppedFiles);
    py_bindfunc(mod, "UnloadDroppedFiles", &cfunc__UnloadDroppedFiles);
    py_bindfunc(mod, "GetFileModTime", &cfunc__GetFileModTime);
    py_bindfunc(mod, "CompressData", &cfunc__CompressData);
    py_bindfunc(mod, "DecompressData", &cfunc__DecompressData);
    py_bindfunc(mod, "EncodeDataBase64", &cfunc__EncodeDataBase64);
    py_bindfunc(mod, "DecodeDataBase64", &cfunc__DecodeDataBase64);
    py_bindfunc(mod, "ComputeCRC32", &cfunc__ComputeCRC32);
    py_bindfunc(mod, "ComputeMD5", &cfunc__ComputeMD5);
    py_bindfunc(mod, "ComputeSHA1", &cfunc__ComputeSHA1);
    py_bindfunc(mod, "LoadAutomationEventList", &cfunc__LoadAutomationEventList);
    py_bindfunc(mod, "UnloadAutomationEventList", &cfunc__UnloadAutomationEventList);
    py_bindfunc(mod, "ExportAutomationEventList", &cfunc__ExportAutomationEventList);
    py_bindfunc(mod, "SetAutomationEventList", &cfunc__SetAutomationEventList);
    py_bindfunc(mod, "SetAutomationEventBaseFrame", &cfunc__SetAutomationEventBaseFrame);
    py_bindfunc(mod, "StartAutomationEventRecording", &cfunc__StartAutomationEventRecording);
    py_bindfunc(mod, "StopAutomationEventRecording", &cfunc__StopAutomationEventRecording);
    py_bindfunc(mod, "PlayAutomationEvent", &cfunc__PlayAutomationEvent);
    py_bindfunc(mod, "IsKeyPressed", &cfunc__IsKeyPressed);
    py_bindfunc(mod, "IsKeyPressedRepeat", &cfunc__IsKeyPressedRepeat);
    py_bindfunc(mod, "IsKeyDown", &cfunc__IsKeyDown);
    py_bindfunc(mod, "IsKeyReleased", &cfunc__IsKeyReleased);
    py_bindfunc(mod, "IsKeyUp", &cfunc__IsKeyUp);
    py_bindfunc(mod, "GetKeyPressed", &cfunc__GetKeyPressed);
    py_bindfunc(mod, "GetCharPressed", &cfunc__GetCharPressed);
    py_bindfunc(mod, "SetExitKey", &cfunc__SetExitKey);
    py_bindfunc(mod, "IsGamepadAvailable", &cfunc__IsGamepadAvailable);
    py_bindfunc(mod, "GetGamepadName", &cfunc__GetGamepadName);
    py_bindfunc(mod, "IsGamepadButtonPressed", &cfunc__IsGamepadButtonPressed);
    py_bindfunc(mod, "IsGamepadButtonDown", &cfunc__IsGamepadButtonDown);
    py_bindfunc(mod, "IsGamepadButtonReleased", &cfunc__IsGamepadButtonReleased);
    py_bindfunc(mod, "IsGamepadButtonUp", &cfunc__IsGamepadButtonUp);
    py_bindfunc(mod, "GetGamepadButtonPressed", &cfunc__GetGamepadButtonPressed);
    py_bindfunc(mod, "GetGamepadAxisCount", &cfunc__GetGamepadAxisCount);
    py_bindfunc(mod, "GetGamepadAxisMovement", &cfunc__GetGamepadAxisMovement);
    py_bindfunc(mod, "SetGamepadMappings", &cfunc__SetGamepadMappings);
    py_bindfunc(mod, "SetGamepadVibration", &cfunc__SetGamepadVibration);
    py_bindfunc(mod, "IsMouseButtonPressed", &cfunc__IsMouseButtonPressed);
    py_bindfunc(mod, "IsMouseButtonDown", &cfunc__IsMouseButtonDown);
    py_bindfunc(mod, "IsMouseButtonReleased", &cfunc__IsMouseButtonReleased);
    py_bindfunc(mod, "IsMouseButtonUp", &cfunc__IsMouseButtonUp);
    py_bindfunc(mod, "GetMouseX", &cfunc__GetMouseX);
    py_bindfunc(mod, "GetMouseY", &cfunc__GetMouseY);
    py_bindfunc(mod, "GetMousePosition", &cfunc__GetMousePosition);
    py_bindfunc(mod, "GetMouseDelta", &cfunc__GetMouseDelta);
    py_bindfunc(mod, "SetMousePosition", &cfunc__SetMousePosition);
    py_bindfunc(mod, "SetMouseOffset", &cfunc__SetMouseOffset);
    py_bindfunc(mod, "SetMouseScale", &cfunc__SetMouseScale);
    py_bindfunc(mod, "GetMouseWheelMove", &cfunc__GetMouseWheelMove);
    py_bindfunc(mod, "GetMouseWheelMoveV", &cfunc__GetMouseWheelMoveV);
    py_bindfunc(mod, "SetMouseCursor", &cfunc__SetMouseCursor);
    py_bindfunc(mod, "GetTouchX", &cfunc__GetTouchX);
    py_bindfunc(mod, "GetTouchY", &cfunc__GetTouchY);
    py_bindfunc(mod, "GetTouchPosition", &cfunc__GetTouchPosition);
    py_bindfunc(mod, "GetTouchPointId", &cfunc__GetTouchPointId);
    py_bindfunc(mod, "GetTouchPointCount", &cfunc__GetTouchPointCount);
    py_bindfunc(mod, "SetGesturesEnabled", &cfunc__SetGesturesEnabled);
    py_bindfunc(mod, "IsGestureDetected", &cfunc__IsGestureDetected);
    py_bindfunc(mod, "GetGestureDetected", &cfunc__GetGestureDetected);
    py_bindfunc(mod, "GetGestureHoldDuration", &cfunc__GetGestureHoldDuration);
    py_bindfunc(mod, "GetGestureDragVector", &cfunc__GetGestureDragVector);
    py_bindfunc(mod, "GetGestureDragAngle", &cfunc__GetGestureDragAngle);
    py_bindfunc(mod, "GetGesturePinchVector", &cfunc__GetGesturePinchVector);
    py_bindfunc(mod, "GetGesturePinchAngle", &cfunc__GetGesturePinchAngle);
    py_bindfunc(mod, "UpdateCamera", &cfunc__UpdateCamera);
    py_bindfunc(mod, "UpdateCameraPro", &cfunc__UpdateCameraPro);
    py_bindfunc(mod, "SetShapesTexture", &cfunc__SetShapesTexture);
    py_bindfunc(mod, "GetShapesTexture", &cfunc__GetShapesTexture);
    py_bindfunc(mod, "GetShapesTextureRectangle", &cfunc__GetShapesTextureRectangle);
    py_bindfunc(mod, "DrawPixel", &cfunc__DrawPixel);
    py_bindfunc(mod, "DrawPixelV", &cfunc__DrawPixelV);
    py_bindfunc(mod, "DrawLine", &cfunc__DrawLine);
    py_bindfunc(mod, "DrawLineV", &cfunc__DrawLineV);
    py_bindfunc(mod, "DrawLineEx", &cfunc__DrawLineEx);
    py_bindfunc(mod, "DrawLineStrip", &cfunc__DrawLineStrip);
    py_bindfunc(mod, "DrawLineBezier", &cfunc__DrawLineBezier);
    py_bindfunc(mod, "DrawCircle", &cfunc__DrawCircle);
    py_bindfunc(mod, "DrawCircleSector", &cfunc__DrawCircleSector);
    py_bindfunc(mod, "DrawCircleSectorLines", &cfunc__DrawCircleSectorLines);
    py_bindfunc(mod, "DrawCircleGradient", &cfunc__DrawCircleGradient);
    py_bindfunc(mod, "DrawCircleV", &cfunc__DrawCircleV);
    py_bindfunc(mod, "DrawCircleLines", &cfunc__DrawCircleLines);
    py_bindfunc(mod, "DrawCircleLinesV", &cfunc__DrawCircleLinesV);
    py_bindfunc(mod, "DrawEllipse", &cfunc__DrawEllipse);
    py_bindfunc(mod, "DrawEllipseLines", &cfunc__DrawEllipseLines);
    py_bindfunc(mod, "DrawRing", &cfunc__DrawRing);
    py_bindfunc(mod, "DrawRingLines", &cfunc__DrawRingLines);
    py_bindfunc(mod, "DrawRectangle", &cfunc__DrawRectangle);
    py_bindfunc(mod, "DrawRectangleV", &cfunc__DrawRectangleV);
    py_bindfunc(mod, "DrawRectangleRec", &cfunc__DrawRectangleRec);
    py_bindfunc(mod, "DrawRectanglePro", &cfunc__DrawRectanglePro);
    py_bindfunc(mod, "DrawRectangleGradientV", &cfunc__DrawRectangleGradientV);
    py_bindfunc(mod, "DrawRectangleGradientH", &cfunc__DrawRectangleGradientH);
    py_bindfunc(mod, "DrawRectangleGradientEx", &cfunc__DrawRectangleGradientEx);
    py_bindfunc(mod, "DrawRectangleLines", &cfunc__DrawRectangleLines);
    py_bindfunc(mod, "DrawRectangleLinesEx", &cfunc__DrawRectangleLinesEx);
    py_bindfunc(mod, "DrawRectangleRounded", &cfunc__DrawRectangleRounded);
    py_bindfunc(mod, "DrawRectangleRoundedLines", &cfunc__DrawRectangleRoundedLines);
    py_bindfunc(mod, "DrawRectangleRoundedLinesEx", &cfunc__DrawRectangleRoundedLinesEx);
    py_bindfunc(mod, "DrawTriangle", &cfunc__DrawTriangle);
    py_bindfunc(mod, "DrawTriangleLines", &cfunc__DrawTriangleLines);
    py_bindfunc(mod, "DrawTriangleFan", &cfunc__DrawTriangleFan);
    py_bindfunc(mod, "DrawTriangleStrip", &cfunc__DrawTriangleStrip);
    py_bindfunc(mod, "DrawPoly", &cfunc__DrawPoly);
    py_bindfunc(mod, "DrawPolyLines", &cfunc__DrawPolyLines);
    py_bindfunc(mod, "DrawPolyLinesEx", &cfunc__DrawPolyLinesEx);
    py_bindfunc(mod, "DrawSplineLinear", &cfunc__DrawSplineLinear);
    py_bindfunc(mod, "DrawSplineBasis", &cfunc__DrawSplineBasis);
    py_bindfunc(mod, "DrawSplineCatmullRom", &cfunc__DrawSplineCatmullRom);
    py_bindfunc(mod, "DrawSplineBezierQuadratic", &cfunc__DrawSplineBezierQuadratic);
    py_bindfunc(mod, "DrawSplineBezierCubic", &cfunc__DrawSplineBezierCubic);
    py_bindfunc(mod, "DrawSplineSegmentLinear", &cfunc__DrawSplineSegmentLinear);
    py_bindfunc(mod, "DrawSplineSegmentBasis", &cfunc__DrawSplineSegmentBasis);
    py_bindfunc(mod, "DrawSplineSegmentCatmullRom", &cfunc__DrawSplineSegmentCatmullRom);
    py_bindfunc(mod, "DrawSplineSegmentBezierQuadratic", &cfunc__DrawSplineSegmentBezierQuadratic);
    py_bindfunc(mod, "DrawSplineSegmentBezierCubic", &cfunc__DrawSplineSegmentBezierCubic);
    py_bindfunc(mod, "GetSplinePointLinear", &cfunc__GetSplinePointLinear);
    py_bindfunc(mod, "GetSplinePointBasis", &cfunc__GetSplinePointBasis);
    py_bindfunc(mod, "GetSplinePointCatmullRom", &cfunc__GetSplinePointCatmullRom);
    py_bindfunc(mod, "GetSplinePointBezierQuad", &cfunc__GetSplinePointBezierQuad);
    py_bindfunc(mod, "GetSplinePointBezierCubic", &cfunc__GetSplinePointBezierCubic);
    py_bindfunc(mod, "CheckCollisionRecs", &cfunc__CheckCollisionRecs);
    py_bindfunc(mod, "CheckCollisionCircles", &cfunc__CheckCollisionCircles);
    py_bindfunc(mod, "CheckCollisionCircleRec", &cfunc__CheckCollisionCircleRec);
    py_bindfunc(mod, "CheckCollisionCircleLine", &cfunc__CheckCollisionCircleLine);
    py_bindfunc(mod, "CheckCollisionPointRec", &cfunc__CheckCollisionPointRec);
    py_bindfunc(mod, "CheckCollisionPointCircle", &cfunc__CheckCollisionPointCircle);
    py_bindfunc(mod, "CheckCollisionPointTriangle", &cfunc__CheckCollisionPointTriangle);
    py_bindfunc(mod, "CheckCollisionPointLine", &cfunc__CheckCollisionPointLine);
    py_bindfunc(mod, "CheckCollisionPointPoly", &cfunc__CheckCollisionPointPoly);
    py_bindfunc(mod, "CheckCollisionLines", &cfunc__CheckCollisionLines);
    py_bindfunc(mod, "GetCollisionRec", &cfunc__GetCollisionRec);
    py_bindfunc(mod, "LoadImage", &cfunc__LoadImage);
    py_bindfunc(mod, "LoadImageRaw", &cfunc__LoadImageRaw);
    py_bindfunc(mod, "LoadImageAnim", &cfunc__LoadImageAnim);
    py_bindfunc(mod, "LoadImageAnimFromMemory", &cfunc__LoadImageAnimFromMemory);
    py_bindfunc(mod, "LoadImageFromMemory", &cfunc__LoadImageFromMemory);
    py_bindfunc(mod, "LoadImageFromTexture", &cfunc__LoadImageFromTexture);
    py_bindfunc(mod, "LoadImageFromScreen", &cfunc__LoadImageFromScreen);
    py_bindfunc(mod, "IsImageValid", &cfunc__IsImageValid);
    py_bindfunc(mod, "UnloadImage", &cfunc__UnloadImage);
    py_bindfunc(mod, "ExportImage", &cfunc__ExportImage);
    py_bindfunc(mod, "ExportImageToMemory", &cfunc__ExportImageToMemory);
    py_bindfunc(mod, "ExportImageAsCode", &cfunc__ExportImageAsCode);
    py_bindfunc(mod, "GenImageColor", &cfunc__GenImageColor);
    py_bindfunc(mod, "GenImageGradientLinear", &cfunc__GenImageGradientLinear);
    py_bindfunc(mod, "GenImageGradientRadial", &cfunc__GenImageGradientRadial);
    py_bindfunc(mod, "GenImageGradientSquare", &cfunc__GenImageGradientSquare);
    py_bindfunc(mod, "GenImageChecked", &cfunc__GenImageChecked);
    py_bindfunc(mod, "GenImageWhiteNoise", &cfunc__GenImageWhiteNoise);
    py_bindfunc(mod, "GenImagePerlinNoise", &cfunc__GenImagePerlinNoise);
    py_bindfunc(mod, "GenImageCellular", &cfunc__GenImageCellular);
    py_bindfunc(mod, "GenImageText", &cfunc__GenImageText);
    py_bindfunc(mod, "ImageCopy", &cfunc__ImageCopy);
    py_bindfunc(mod, "ImageFromImage", &cfunc__ImageFromImage);
    py_bindfunc(mod, "ImageFromChannel", &cfunc__ImageFromChannel);
    py_bindfunc(mod, "ImageText", &cfunc__ImageText);
    py_bindfunc(mod, "ImageTextEx", &cfunc__ImageTextEx);
    py_bindfunc(mod, "ImageFormat", &cfunc__ImageFormat);
    py_bindfunc(mod, "ImageToPOT", &cfunc__ImageToPOT);
    py_bindfunc(mod, "ImageCrop", &cfunc__ImageCrop);
    py_bindfunc(mod, "ImageAlphaCrop", &cfunc__ImageAlphaCrop);
    py_bindfunc(mod, "ImageAlphaClear", &cfunc__ImageAlphaClear);
    py_bindfunc(mod, "ImageAlphaMask", &cfunc__ImageAlphaMask);
    py_bindfunc(mod, "ImageAlphaPremultiply", &cfunc__ImageAlphaPremultiply);
    py_bindfunc(mod, "ImageBlurGaussian", &cfunc__ImageBlurGaussian);
    py_bindfunc(mod, "ImageKernelConvolution", &cfunc__ImageKernelConvolution);
    py_bindfunc(mod, "ImageResize", &cfunc__ImageResize);
    py_bindfunc(mod, "ImageResizeNN", &cfunc__ImageResizeNN);
    py_bindfunc(mod, "ImageResizeCanvas", &cfunc__ImageResizeCanvas);
    py_bindfunc(mod, "ImageMipmaps", &cfunc__ImageMipmaps);
    py_bindfunc(mod, "ImageDither", &cfunc__ImageDither);
    py_bindfunc(mod, "ImageFlipVertical", &cfunc__ImageFlipVertical);
    py_bindfunc(mod, "ImageFlipHorizontal", &cfunc__ImageFlipHorizontal);
    py_bindfunc(mod, "ImageRotate", &cfunc__ImageRotate);
    py_bindfunc(mod, "ImageRotateCW", &cfunc__ImageRotateCW);
    py_bindfunc(mod, "ImageRotateCCW", &cfunc__ImageRotateCCW);
    py_bindfunc(mod, "ImageColorTint", &cfunc__ImageColorTint);
    py_bindfunc(mod, "ImageColorInvert", &cfunc__ImageColorInvert);
    py_bindfunc(mod, "ImageColorGrayscale", &cfunc__ImageColorGrayscale);
    py_bindfunc(mod, "ImageColorContrast", &cfunc__ImageColorContrast);
    py_bindfunc(mod, "ImageColorBrightness", &cfunc__ImageColorBrightness);
    py_bindfunc(mod, "ImageColorReplace", &cfunc__ImageColorReplace);
    py_bindfunc(mod, "LoadImageColors", &cfunc__LoadImageColors);
    py_bindfunc(mod, "LoadImagePalette", &cfunc__LoadImagePalette);
    py_bindfunc(mod, "UnloadImageColors", &cfunc__UnloadImageColors);
    py_bindfunc(mod, "UnloadImagePalette", &cfunc__UnloadImagePalette);
    py_bindfunc(mod, "GetImageAlphaBorder", &cfunc__GetImageAlphaBorder);
    py_bindfunc(mod, "GetImageColor", &cfunc__GetImageColor);
    py_bindfunc(mod, "ImageClearBackground", &cfunc__ImageClearBackground);
    py_bindfunc(mod, "ImageDrawPixel", &cfunc__ImageDrawPixel);
    py_bindfunc(mod, "ImageDrawPixelV", &cfunc__ImageDrawPixelV);
    py_bindfunc(mod, "ImageDrawLine", &cfunc__ImageDrawLine);
    py_bindfunc(mod, "ImageDrawLineV", &cfunc__ImageDrawLineV);
    py_bindfunc(mod, "ImageDrawLineEx", &cfunc__ImageDrawLineEx);
    py_bindfunc(mod, "ImageDrawCircle", &cfunc__ImageDrawCircle);
    py_bindfunc(mod, "ImageDrawCircleV", &cfunc__ImageDrawCircleV);
    py_bindfunc(mod, "ImageDrawCircleLines", &cfunc__ImageDrawCircleLines);
    py_bindfunc(mod, "ImageDrawCircleLinesV", &cfunc__ImageDrawCircleLinesV);
    py_bindfunc(mod, "ImageDrawRectangle", &cfunc__ImageDrawRectangle);
    py_bindfunc(mod, "ImageDrawRectangleV", &cfunc__ImageDrawRectangleV);
    py_bindfunc(mod, "ImageDrawRectangleRec", &cfunc__ImageDrawRectangleRec);
    py_bindfunc(mod, "ImageDrawRectangleLines", &cfunc__ImageDrawRectangleLines);
    py_bindfunc(mod, "ImageDrawTriangle", &cfunc__ImageDrawTriangle);
    py_bindfunc(mod, "ImageDrawTriangleEx", &cfunc__ImageDrawTriangleEx);
    py_bindfunc(mod, "ImageDrawTriangleLines", &cfunc__ImageDrawTriangleLines);
    py_bindfunc(mod, "ImageDrawTriangleFan", &cfunc__ImageDrawTriangleFan);
    py_bindfunc(mod, "ImageDrawTriangleStrip", &cfunc__ImageDrawTriangleStrip);
    py_bindfunc(mod, "ImageDraw", &cfunc__ImageDraw);
    py_bindfunc(mod, "ImageDrawText", &cfunc__ImageDrawText);
    py_bindfunc(mod, "ImageDrawTextEx", &cfunc__ImageDrawTextEx);
    py_bindfunc(mod, "LoadTexture", &cfunc__LoadTexture);
    py_bindfunc(mod, "LoadTextureFromImage", &cfunc__LoadTextureFromImage);
    py_bindfunc(mod, "LoadTextureCubemap", &cfunc__LoadTextureCubemap);
    py_bindfunc(mod, "LoadRenderTexture", &cfunc__LoadRenderTexture);
    py_bindfunc(mod, "IsTextureValid", &cfunc__IsTextureValid);
    py_bindfunc(mod, "UnloadTexture", &cfunc__UnloadTexture);
    py_bindfunc(mod, "IsRenderTextureValid", &cfunc__IsRenderTextureValid);
    py_bindfunc(mod, "UnloadRenderTexture", &cfunc__UnloadRenderTexture);
    py_bindfunc(mod, "UpdateTexture", &cfunc__UpdateTexture);
    py_bindfunc(mod, "UpdateTextureRec", &cfunc__UpdateTextureRec);
    py_bindfunc(mod, "GenTextureMipmaps", &cfunc__GenTextureMipmaps);
    py_bindfunc(mod, "SetTextureFilter", &cfunc__SetTextureFilter);
    py_bindfunc(mod, "SetTextureWrap", &cfunc__SetTextureWrap);
    py_bindfunc(mod, "DrawTexture", &cfunc__DrawTexture);
    py_bindfunc(mod, "DrawTextureV", &cfunc__DrawTextureV);
    py_bindfunc(mod, "DrawTextureEx", &cfunc__DrawTextureEx);
    py_bindfunc(mod, "DrawTextureRec", &cfunc__DrawTextureRec);
    py_bindfunc(mod, "DrawTexturePro", &cfunc__DrawTexturePro);
    py_bindfunc(mod, "DrawTextureNPatch", &cfunc__DrawTextureNPatch);
    py_bindfunc(mod, "ColorIsEqual", &cfunc__ColorIsEqual);
    py_bindfunc(mod, "Fade", &cfunc__Fade);
    py_bindfunc(mod, "ColorToInt", &cfunc__ColorToInt);
    py_bindfunc(mod, "ColorNormalize", &cfunc__ColorNormalize);
    py_bindfunc(mod, "ColorFromNormalized", &cfunc__ColorFromNormalized);
    py_bindfunc(mod, "ColorToHSV", &cfunc__ColorToHSV);
    py_bindfunc(mod, "ColorFromHSV", &cfunc__ColorFromHSV);
    py_bindfunc(mod, "ColorTint", &cfunc__ColorTint);
    py_bindfunc(mod, "ColorBrightness", &cfunc__ColorBrightness);
    py_bindfunc(mod, "ColorContrast", &cfunc__ColorContrast);
    py_bindfunc(mod, "ColorAlpha", &cfunc__ColorAlpha);
    py_bindfunc(mod, "ColorAlphaBlend", &cfunc__ColorAlphaBlend);
    py_bindfunc(mod, "ColorLerp", &cfunc__ColorLerp);
    py_bindfunc(mod, "GetColor", &cfunc__GetColor);
    py_bindfunc(mod, "GetPixelColor", &cfunc__GetPixelColor);
    py_bindfunc(mod, "SetPixelColor", &cfunc__SetPixelColor);
    py_bindfunc(mod, "GetPixelDataSize", &cfunc__GetPixelDataSize);
    py_bindfunc(mod, "GetFontDefault", &cfunc__GetFontDefault);
    py_bindfunc(mod, "LoadFont", &cfunc__LoadFont);
    py_bindfunc(mod, "LoadFontEx", &cfunc__LoadFontEx);
    py_bindfunc(mod, "LoadFontFromImage", &cfunc__LoadFontFromImage);
    py_bindfunc(mod, "LoadFontFromMemory", &cfunc__LoadFontFromMemory);
    py_bindfunc(mod, "IsFontValid", &cfunc__IsFontValid);
    py_bindfunc(mod, "LoadFontData", &cfunc__LoadFontData);
    py_bindfunc(mod, "GenImageFontAtlas", &cfunc__GenImageFontAtlas);
    py_bindfunc(mod, "UnloadFontData", &cfunc__UnloadFontData);
    py_bindfunc(mod, "UnloadFont", &cfunc__UnloadFont);
    py_bindfunc(mod, "ExportFontAsCode", &cfunc__ExportFontAsCode);
    py_bindfunc(mod, "DrawFPS", &cfunc__DrawFPS);
    py_bindfunc(mod, "DrawText", &cfunc__DrawText);
    py_bindfunc(mod, "DrawTextEx", &cfunc__DrawTextEx);
    py_bindfunc(mod, "DrawTextPro", &cfunc__DrawTextPro);
    py_bindfunc(mod, "DrawTextCodepoint", &cfunc__DrawTextCodepoint);
    py_bindfunc(mod, "DrawTextCodepoints", &cfunc__DrawTextCodepoints);
    py_bindfunc(mod, "SetTextLineSpacing", &cfunc__SetTextLineSpacing);
    py_bindfunc(mod, "MeasureText", &cfunc__MeasureText);
    py_bindfunc(mod, "MeasureTextEx", &cfunc__MeasureTextEx);
    py_bindfunc(mod, "GetGlyphIndex", &cfunc__GetGlyphIndex);
    py_bindfunc(mod, "GetGlyphInfo", &cfunc__GetGlyphInfo);
    py_bindfunc(mod, "GetGlyphAtlasRec", &cfunc__GetGlyphAtlasRec);
    py_bindfunc(mod, "LoadUTF8", &cfunc__LoadUTF8);
    py_bindfunc(mod, "UnloadUTF8", &cfunc__UnloadUTF8);
    py_bindfunc(mod, "LoadCodepoints", &cfunc__LoadCodepoints);
    py_bindfunc(mod, "UnloadCodepoints", &cfunc__UnloadCodepoints);
    py_bindfunc(mod, "GetCodepointCount", &cfunc__GetCodepointCount);
    py_bindfunc(mod, "GetCodepoint", &cfunc__GetCodepoint);
    py_bindfunc(mod, "GetCodepointNext", &cfunc__GetCodepointNext);
    py_bindfunc(mod, "GetCodepointPrevious", &cfunc__GetCodepointPrevious);
    py_bindfunc(mod, "CodepointToUTF8", &cfunc__CodepointToUTF8);
    py_bindfunc(mod, "TextCopy", &cfunc__TextCopy);
    py_bindfunc(mod, "TextIsEqual", &cfunc__TextIsEqual);
    py_bindfunc(mod, "TextLength", &cfunc__TextLength);
    py_bindfunc(mod, "TextSubtext", &cfunc__TextSubtext);
    py_bindfunc(mod, "TextReplace", &cfunc__TextReplace);
    py_bindfunc(mod, "TextInsert", &cfunc__TextInsert);
    py_bindfunc(mod, "TextJoin", &cfunc__TextJoin);
    py_bindfunc(mod, "TextSplit", &cfunc__TextSplit);
    py_bindfunc(mod, "TextAppend", &cfunc__TextAppend);
    py_bindfunc(mod, "TextFindIndex", &cfunc__TextFindIndex);
    py_bindfunc(mod, "TextToUpper", &cfunc__TextToUpper);
    py_bindfunc(mod, "TextToLower", &cfunc__TextToLower);
    py_bindfunc(mod, "TextToPascal", &cfunc__TextToPascal);
    py_bindfunc(mod, "TextToSnake", &cfunc__TextToSnake);
    py_bindfunc(mod, "TextToCamel", &cfunc__TextToCamel);
    py_bindfunc(mod, "TextToInteger", &cfunc__TextToInteger);
    py_bindfunc(mod, "TextToFloat", &cfunc__TextToFloat);
    py_bindfunc(mod, "DrawLine3D", &cfunc__DrawLine3D);
    py_bindfunc(mod, "DrawPoint3D", &cfunc__DrawPoint3D);
    py_bindfunc(mod, "DrawCircle3D", &cfunc__DrawCircle3D);
    py_bindfunc(mod, "DrawTriangle3D", &cfunc__DrawTriangle3D);
    py_bindfunc(mod, "DrawTriangleStrip3D", &cfunc__DrawTriangleStrip3D);
    py_bindfunc(mod, "DrawCube", &cfunc__DrawCube);
    py_bindfunc(mod, "DrawCubeV", &cfunc__DrawCubeV);
    py_bindfunc(mod, "DrawCubeWires", &cfunc__DrawCubeWires);
    py_bindfunc(mod, "DrawCubeWiresV", &cfunc__DrawCubeWiresV);
    py_bindfunc(mod, "DrawSphere", &cfunc__DrawSphere);
    py_bindfunc(mod, "DrawSphereEx", &cfunc__DrawSphereEx);
    py_bindfunc(mod, "DrawSphereWires", &cfunc__DrawSphereWires);
    py_bindfunc(mod, "DrawCylinder", &cfunc__DrawCylinder);
    py_bindfunc(mod, "DrawCylinderEx", &cfunc__DrawCylinderEx);
    py_bindfunc(mod, "DrawCylinderWires", &cfunc__DrawCylinderWires);
    py_bindfunc(mod, "DrawCylinderWiresEx", &cfunc__DrawCylinderWiresEx);
    py_bindfunc(mod, "DrawCapsule", &cfunc__DrawCapsule);
    py_bindfunc(mod, "DrawCapsuleWires", &cfunc__DrawCapsuleWires);
    py_bindfunc(mod, "DrawPlane", &cfunc__DrawPlane);
    py_bindfunc(mod, "DrawRay", &cfunc__DrawRay);
    py_bindfunc(mod, "DrawGrid", &cfunc__DrawGrid);
    py_bindfunc(mod, "LoadModel", &cfunc__LoadModel);
    py_bindfunc(mod, "LoadModelFromMesh", &cfunc__LoadModelFromMesh);
    py_bindfunc(mod, "IsModelValid", &cfunc__IsModelValid);
    py_bindfunc(mod, "UnloadModel", &cfunc__UnloadModel);
    py_bindfunc(mod, "GetModelBoundingBox", &cfunc__GetModelBoundingBox);
    py_bindfunc(mod, "DrawModel", &cfunc__DrawModel);
    py_bindfunc(mod, "DrawModelEx", &cfunc__DrawModelEx);
    py_bindfunc(mod, "DrawModelWires", &cfunc__DrawModelWires);
    py_bindfunc(mod, "DrawModelWiresEx", &cfunc__DrawModelWiresEx);
    py_bindfunc(mod, "DrawModelPoints", &cfunc__DrawModelPoints);
    py_bindfunc(mod, "DrawModelPointsEx", &cfunc__DrawModelPointsEx);
    py_bindfunc(mod, "DrawBoundingBox", &cfunc__DrawBoundingBox);
    py_bindfunc(mod, "DrawBillboard", &cfunc__DrawBillboard);
    py_bindfunc(mod, "DrawBillboardRec", &cfunc__DrawBillboardRec);
    py_bindfunc(mod, "DrawBillboardPro", &cfunc__DrawBillboardPro);
    py_bindfunc(mod, "UploadMesh", &cfunc__UploadMesh);
    py_bindfunc(mod, "UpdateMeshBuffer", &cfunc__UpdateMeshBuffer);
    py_bindfunc(mod, "UnloadMesh", &cfunc__UnloadMesh);
    py_bindfunc(mod, "DrawMesh", &cfunc__DrawMesh);
    py_bindfunc(mod, "DrawMeshInstanced", &cfunc__DrawMeshInstanced);
    py_bindfunc(mod, "GetMeshBoundingBox", &cfunc__GetMeshBoundingBox);
    py_bindfunc(mod, "GenMeshTangents", &cfunc__GenMeshTangents);
    py_bindfunc(mod, "ExportMesh", &cfunc__ExportMesh);
    py_bindfunc(mod, "ExportMeshAsCode", &cfunc__ExportMeshAsCode);
    py_bindfunc(mod, "GenMeshPoly", &cfunc__GenMeshPoly);
    py_bindfunc(mod, "GenMeshPlane", &cfunc__GenMeshPlane);
    py_bindfunc(mod, "GenMeshCube", &cfunc__GenMeshCube);
    py_bindfunc(mod, "GenMeshSphere", &cfunc__GenMeshSphere);
    py_bindfunc(mod, "GenMeshHemiSphere", &cfunc__GenMeshHemiSphere);
    py_bindfunc(mod, "GenMeshCylinder", &cfunc__GenMeshCylinder);
    py_bindfunc(mod, "GenMeshCone", &cfunc__GenMeshCone);
    py_bindfunc(mod, "GenMeshTorus", &cfunc__GenMeshTorus);
    py_bindfunc(mod, "GenMeshKnot", &cfunc__GenMeshKnot);
    py_bindfunc(mod, "GenMeshHeightmap", &cfunc__GenMeshHeightmap);
    py_bindfunc(mod, "GenMeshCubicmap", &cfunc__GenMeshCubicmap);
    py_bindfunc(mod, "LoadMaterials", &cfunc__LoadMaterials);
    py_bindfunc(mod, "LoadMaterialDefault", &cfunc__LoadMaterialDefault);
    py_bindfunc(mod, "IsMaterialValid", &cfunc__IsMaterialValid);
    py_bindfunc(mod, "UnloadMaterial", &cfunc__UnloadMaterial);
    py_bindfunc(mod, "SetMaterialTexture", &cfunc__SetMaterialTexture);
    py_bindfunc(mod, "SetModelMeshMaterial", &cfunc__SetModelMeshMaterial);
    py_bindfunc(mod, "LoadModelAnimations", &cfunc__LoadModelAnimations);
    py_bindfunc(mod, "UpdateModelAnimation", &cfunc__UpdateModelAnimation);
    py_bindfunc(mod, "UpdateModelAnimationBones", &cfunc__UpdateModelAnimationBones);
    py_bindfunc(mod, "UnloadModelAnimation", &cfunc__UnloadModelAnimation);
    py_bindfunc(mod, "UnloadModelAnimations", &cfunc__UnloadModelAnimations);
    py_bindfunc(mod, "IsModelAnimationValid", &cfunc__IsModelAnimationValid);
    py_bindfunc(mod, "CheckCollisionSpheres", &cfunc__CheckCollisionSpheres);
    py_bindfunc(mod, "CheckCollisionBoxes", &cfunc__CheckCollisionBoxes);
    py_bindfunc(mod, "CheckCollisionBoxSphere", &cfunc__CheckCollisionBoxSphere);
    py_bindfunc(mod, "GetRayCollisionSphere", &cfunc__GetRayCollisionSphere);
    py_bindfunc(mod, "GetRayCollisionBox", &cfunc__GetRayCollisionBox);
    py_bindfunc(mod, "GetRayCollisionMesh", &cfunc__GetRayCollisionMesh);
    py_bindfunc(mod, "GetRayCollisionTriangle", &cfunc__GetRayCollisionTriangle);
    py_bindfunc(mod, "GetRayCollisionQuad", &cfunc__GetRayCollisionQuad);
    py_bindfunc(mod, "InitAudioDevice", &cfunc__InitAudioDevice);
    py_bindfunc(mod, "CloseAudioDevice", &cfunc__CloseAudioDevice);
    py_bindfunc(mod, "IsAudioDeviceReady", &cfunc__IsAudioDeviceReady);
    py_bindfunc(mod, "SetMasterVolume", &cfunc__SetMasterVolume);
    py_bindfunc(mod, "GetMasterVolume", &cfunc__GetMasterVolume);
    py_bindfunc(mod, "LoadWave", &cfunc__LoadWave);
    py_bindfunc(mod, "LoadWaveFromMemory", &cfunc__LoadWaveFromMemory);
    py_bindfunc(mod, "IsWaveValid", &cfunc__IsWaveValid);
    py_bindfunc(mod, "LoadSound", &cfunc__LoadSound);
    py_bindfunc(mod, "LoadSoundFromWave", &cfunc__LoadSoundFromWave);
    py_bindfunc(mod, "LoadSoundAlias", &cfunc__LoadSoundAlias);
    py_bindfunc(mod, "IsSoundValid", &cfunc__IsSoundValid);
    py_bindfunc(mod, "UpdateSound", &cfunc__UpdateSound);
    py_bindfunc(mod, "UnloadWave", &cfunc__UnloadWave);
    py_bindfunc(mod, "UnloadSound", &cfunc__UnloadSound);
    py_bindfunc(mod, "UnloadSoundAlias", &cfunc__UnloadSoundAlias);
    py_bindfunc(mod, "ExportWave", &cfunc__ExportWave);
    py_bindfunc(mod, "ExportWaveAsCode", &cfunc__ExportWaveAsCode);
    py_bindfunc(mod, "PlaySound", &cfunc__PlaySound);
    py_bindfunc(mod, "StopSound", &cfunc__StopSound);
    py_bindfunc(mod, "PauseSound", &cfunc__PauseSound);
    py_bindfunc(mod, "ResumeSound", &cfunc__ResumeSound);
    py_bindfunc(mod, "IsSoundPlaying", &cfunc__IsSoundPlaying);
    py_bindfunc(mod, "SetSoundVolume", &cfunc__SetSoundVolume);
    py_bindfunc(mod, "SetSoundPitch", &cfunc__SetSoundPitch);
    py_bindfunc(mod, "SetSoundPan", &cfunc__SetSoundPan);
    py_bindfunc(mod, "WaveCopy", &cfunc__WaveCopy);
    py_bindfunc(mod, "WaveCrop", &cfunc__WaveCrop);
    py_bindfunc(mod, "WaveFormat", &cfunc__WaveFormat);
    py_bindfunc(mod, "LoadWaveSamples", &cfunc__LoadWaveSamples);
    py_bindfunc(mod, "UnloadWaveSamples", &cfunc__UnloadWaveSamples);
    py_bindfunc(mod, "LoadMusicStream", &cfunc__LoadMusicStream);
    py_bindfunc(mod, "LoadMusicStreamFromMemory", &cfunc__LoadMusicStreamFromMemory);
    py_bindfunc(mod, "IsMusicValid", &cfunc__IsMusicValid);
    py_bindfunc(mod, "UnloadMusicStream", &cfunc__UnloadMusicStream);
    py_bindfunc(mod, "PlayMusicStream", &cfunc__PlayMusicStream);
    py_bindfunc(mod, "IsMusicStreamPlaying", &cfunc__IsMusicStreamPlaying);
    py_bindfunc(mod, "UpdateMusicStream", &cfunc__UpdateMusicStream);
    py_bindfunc(mod, "StopMusicStream", &cfunc__StopMusicStream);
    py_bindfunc(mod, "PauseMusicStream", &cfunc__PauseMusicStream);
    py_bindfunc(mod, "ResumeMusicStream", &cfunc__ResumeMusicStream);
    py_bindfunc(mod, "SeekMusicStream", &cfunc__SeekMusicStream);
    py_bindfunc(mod, "SetMusicVolume", &cfunc__SetMusicVolume);
    py_bindfunc(mod, "SetMusicPitch", &cfunc__SetMusicPitch);
    py_bindfunc(mod, "SetMusicPan", &cfunc__SetMusicPan);
    py_bindfunc(mod, "GetMusicTimeLength", &cfunc__GetMusicTimeLength);
    py_bindfunc(mod, "GetMusicTimePlayed", &cfunc__GetMusicTimePlayed);
    py_bindfunc(mod, "LoadAudioStream", &cfunc__LoadAudioStream);
    py_bindfunc(mod, "IsAudioStreamValid", &cfunc__IsAudioStreamValid);
    py_bindfunc(mod, "UnloadAudioStream", &cfunc__UnloadAudioStream);
    py_bindfunc(mod, "UpdateAudioStream", &cfunc__UpdateAudioStream);
    py_bindfunc(mod, "IsAudioStreamProcessed", &cfunc__IsAudioStreamProcessed);
    py_bindfunc(mod, "PlayAudioStream", &cfunc__PlayAudioStream);
    py_bindfunc(mod, "PauseAudioStream", &cfunc__PauseAudioStream);
    py_bindfunc(mod, "ResumeAudioStream", &cfunc__ResumeAudioStream);
    py_bindfunc(mod, "IsAudioStreamPlaying", &cfunc__IsAudioStreamPlaying);
    py_bindfunc(mod, "StopAudioStream", &cfunc__StopAudioStream);
    py_bindfunc(mod, "SetAudioStreamVolume", &cfunc__SetAudioStreamVolume);
    py_bindfunc(mod, "SetAudioStreamPitch", &cfunc__SetAudioStreamPitch);
    py_bindfunc(mod, "SetAudioStreamPan", &cfunc__SetAudioStreamPan);
    py_bindfunc(mod, "SetAudioStreamBufferSizeDefault", &cfunc__SetAudioStreamBufferSizeDefault);
    /* enums */
    ADD_ENUM(FLAG_VSYNC_HINT);
    ADD_ENUM(FLAG_FULLSCREEN_MODE);
    ADD_ENUM(FLAG_WINDOW_RESIZABLE);
    ADD_ENUM(FLAG_WINDOW_UNDECORATED);
    ADD_ENUM(FLAG_WINDOW_HIDDEN);
    ADD_ENUM(FLAG_WINDOW_MINIMIZED);
    ADD_ENUM(FLAG_WINDOW_MAXIMIZED);
    ADD_ENUM(FLAG_WINDOW_UNFOCUSED);
    ADD_ENUM(FLAG_WINDOW_TOPMOST);
    ADD_ENUM(FLAG_WINDOW_ALWAYS_RUN);
    ADD_ENUM(FLAG_WINDOW_TRANSPARENT);
    ADD_ENUM(FLAG_WINDOW_HIGHDPI);
    ADD_ENUM(FLAG_WINDOW_MOUSE_PASSTHROUGH);
    ADD_ENUM(FLAG_BORDERLESS_WINDOWED_MODE);
    ADD_ENUM(FLAG_MSAA_4X_HINT);
    ADD_ENUM(FLAG_INTERLACED_HINT);
    ADD_ENUM(LOG_ALL);
    ADD_ENUM(LOG_TRACE);
    ADD_ENUM(LOG_DEBUG);
    ADD_ENUM(LOG_INFO);
    ADD_ENUM(LOG_WARNING);
    ADD_ENUM(LOG_ERROR);
    ADD_ENUM(LOG_FATAL);
    ADD_ENUM(LOG_NONE);
    ADD_ENUM(KEY_NULL);
    ADD_ENUM(KEY_APOSTROPHE);
    ADD_ENUM(KEY_COMMA);
    ADD_ENUM(KEY_MINUS);
    ADD_ENUM(KEY_PERIOD);
    ADD_ENUM(KEY_SLASH);
    ADD_ENUM(KEY_ZERO);
    ADD_ENUM(KEY_ONE);
    ADD_ENUM(KEY_TWO);
    ADD_ENUM(KEY_THREE);
    ADD_ENUM(KEY_FOUR);
    ADD_ENUM(KEY_FIVE);
    ADD_ENUM(KEY_SIX);
    ADD_ENUM(KEY_SEVEN);
    ADD_ENUM(KEY_EIGHT);
    ADD_ENUM(KEY_NINE);
    ADD_ENUM(KEY_SEMICOLON);
    ADD_ENUM(KEY_EQUAL);
    ADD_ENUM(KEY_A);
    ADD_ENUM(KEY_B);
    ADD_ENUM(KEY_C);
    ADD_ENUM(KEY_D);
    ADD_ENUM(KEY_E);
    ADD_ENUM(KEY_F);
    ADD_ENUM(KEY_G);
    ADD_ENUM(KEY_H);
    ADD_ENUM(KEY_I);
    ADD_ENUM(KEY_J);
    ADD_ENUM(KEY_K);
    ADD_ENUM(KEY_L);
    ADD_ENUM(KEY_M);
    ADD_ENUM(KEY_N);
    ADD_ENUM(KEY_O);
    ADD_ENUM(KEY_P);
    ADD_ENUM(KEY_Q);
    ADD_ENUM(KEY_R);
    ADD_ENUM(KEY_S);
    ADD_ENUM(KEY_T);
    ADD_ENUM(KEY_U);
    ADD_ENUM(KEY_V);
    ADD_ENUM(KEY_W);
    ADD_ENUM(KEY_X);
    ADD_ENUM(KEY_Y);
    ADD_ENUM(KEY_Z);
    ADD_ENUM(KEY_LEFT_BRACKET);
    ADD_ENUM(KEY_BACKSLASH);
    ADD_ENUM(KEY_RIGHT_BRACKET);
    ADD_ENUM(KEY_GRAVE);
    ADD_ENUM(KEY_SPACE);
    ADD_ENUM(KEY_ESCAPE);
    ADD_ENUM(KEY_ENTER);
    ADD_ENUM(KEY_TAB);
    ADD_ENUM(KEY_BACKSPACE);
    ADD_ENUM(KEY_INSERT);
    ADD_ENUM(KEY_DELETE);
    ADD_ENUM(KEY_RIGHT);
    ADD_ENUM(KEY_LEFT);
    ADD_ENUM(KEY_DOWN);
    ADD_ENUM(KEY_UP);
    ADD_ENUM(KEY_PAGE_UP);
    ADD_ENUM(KEY_PAGE_DOWN);
    ADD_ENUM(KEY_HOME);
    ADD_ENUM(KEY_END);
    ADD_ENUM(KEY_CAPS_LOCK);
    ADD_ENUM(KEY_SCROLL_LOCK);
    ADD_ENUM(KEY_NUM_LOCK);
    ADD_ENUM(KEY_PRINT_SCREEN);
    ADD_ENUM(KEY_PAUSE);
    ADD_ENUM(KEY_F1);
    ADD_ENUM(KEY_F2);
    ADD_ENUM(KEY_F3);
    ADD_ENUM(KEY_F4);
    ADD_ENUM(KEY_F5);
    ADD_ENUM(KEY_F6);
    ADD_ENUM(KEY_F7);
    ADD_ENUM(KEY_F8);
    ADD_ENUM(KEY_F9);
    ADD_ENUM(KEY_F10);
    ADD_ENUM(KEY_F11);
    ADD_ENUM(KEY_F12);
    ADD_ENUM(KEY_LEFT_SHIFT);
    ADD_ENUM(KEY_LEFT_CONTROL);
    ADD_ENUM(KEY_LEFT_ALT);
    ADD_ENUM(KEY_LEFT_SUPER);
    ADD_ENUM(KEY_RIGHT_SHIFT);
    ADD_ENUM(KEY_RIGHT_CONTROL);
    ADD_ENUM(KEY_RIGHT_ALT);
    ADD_ENUM(KEY_RIGHT_SUPER);
    ADD_ENUM(KEY_KB_MENU);
    ADD_ENUM(KEY_KP_0);
    ADD_ENUM(KEY_KP_1);
    ADD_ENUM(KEY_KP_2);
    ADD_ENUM(KEY_KP_3);
    ADD_ENUM(KEY_KP_4);
    ADD_ENUM(KEY_KP_5);
    ADD_ENUM(KEY_KP_6);
    ADD_ENUM(KEY_KP_7);
    ADD_ENUM(KEY_KP_8);
    ADD_ENUM(KEY_KP_9);
    ADD_ENUM(KEY_KP_DECIMAL);
    ADD_ENUM(KEY_KP_DIVIDE);
    ADD_ENUM(KEY_KP_MULTIPLY);
    ADD_ENUM(KEY_KP_SUBTRACT);
    ADD_ENUM(KEY_KP_ADD);
    ADD_ENUM(KEY_KP_ENTER);
    ADD_ENUM(KEY_KP_EQUAL);
    ADD_ENUM(KEY_BACK);
    ADD_ENUM(KEY_MENU);
    ADD_ENUM(KEY_VOLUME_UP);
    ADD_ENUM(KEY_VOLUME_DOWN);
    ADD_ENUM(MOUSE_BUTTON_LEFT);
    ADD_ENUM(MOUSE_BUTTON_RIGHT);
    ADD_ENUM(MOUSE_BUTTON_MIDDLE);
    ADD_ENUM(MOUSE_BUTTON_SIDE);
    ADD_ENUM(MOUSE_BUTTON_EXTRA);
    ADD_ENUM(MOUSE_BUTTON_FORWARD);
    ADD_ENUM(MOUSE_BUTTON_BACK);
    ADD_ENUM(MOUSE_CURSOR_DEFAULT);
    ADD_ENUM(MOUSE_CURSOR_ARROW);
    ADD_ENUM(MOUSE_CURSOR_IBEAM);
    ADD_ENUM(MOUSE_CURSOR_CROSSHAIR);
    ADD_ENUM(MOUSE_CURSOR_POINTING_HAND);
    ADD_ENUM(MOUSE_CURSOR_RESIZE_EW);
    ADD_ENUM(MOUSE_CURSOR_RESIZE_NS);
    ADD_ENUM(MOUSE_CURSOR_RESIZE_NWSE);
    ADD_ENUM(MOUSE_CURSOR_RESIZE_NESW);
    ADD_ENUM(MOUSE_CURSOR_RESIZE_ALL);
    ADD_ENUM(MOUSE_CURSOR_NOT_ALLOWED);
    ADD_ENUM(GAMEPAD_BUTTON_UNKNOWN);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_UP);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_DOWN);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_FACE_LEFT);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_UP);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_TRIGGER_1);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_TRIGGER_2);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_TRIGGER_2);
    ADD_ENUM(GAMEPAD_BUTTON_MIDDLE_LEFT);
    ADD_ENUM(GAMEPAD_BUTTON_MIDDLE);
    ADD_ENUM(GAMEPAD_BUTTON_MIDDLE_RIGHT);
    ADD_ENUM(GAMEPAD_BUTTON_LEFT_THUMB);
    ADD_ENUM(GAMEPAD_BUTTON_RIGHT_THUMB);
    ADD_ENUM(GAMEPAD_AXIS_LEFT_X);
    ADD_ENUM(GAMEPAD_AXIS_LEFT_Y);
    ADD_ENUM(GAMEPAD_AXIS_RIGHT_X);
    ADD_ENUM(GAMEPAD_AXIS_RIGHT_Y);
    ADD_ENUM(GAMEPAD_AXIS_LEFT_TRIGGER);
    ADD_ENUM(GAMEPAD_AXIS_RIGHT_TRIGGER);
    ADD_ENUM(MATERIAL_MAP_ALBEDO);
    ADD_ENUM(MATERIAL_MAP_METALNESS);
    ADD_ENUM(MATERIAL_MAP_NORMAL);
    ADD_ENUM(MATERIAL_MAP_ROUGHNESS);
    ADD_ENUM(MATERIAL_MAP_OCCLUSION);
    ADD_ENUM(MATERIAL_MAP_EMISSION);
    ADD_ENUM(MATERIAL_MAP_HEIGHT);
    ADD_ENUM(MATERIAL_MAP_CUBEMAP);
    ADD_ENUM(MATERIAL_MAP_IRRADIANCE);
    ADD_ENUM(MATERIAL_MAP_PREFILTER);
    ADD_ENUM(MATERIAL_MAP_BRDF);
    ADD_ENUM(SHADER_LOC_VERTEX_POSITION);
    ADD_ENUM(SHADER_LOC_VERTEX_TEXCOORD01);
    ADD_ENUM(SHADER_LOC_VERTEX_TEXCOORD02);
    ADD_ENUM(SHADER_LOC_VERTEX_NORMAL);
    ADD_ENUM(SHADER_LOC_VERTEX_TANGENT);
    ADD_ENUM(SHADER_LOC_VERTEX_COLOR);
    ADD_ENUM(SHADER_LOC_MATRIX_MVP);
    ADD_ENUM(SHADER_LOC_MATRIX_VIEW);
    ADD_ENUM(SHADER_LOC_MATRIX_PROJECTION);
    ADD_ENUM(SHADER_LOC_MATRIX_MODEL);
    ADD_ENUM(SHADER_LOC_MATRIX_NORMAL);
    ADD_ENUM(SHADER_LOC_VECTOR_VIEW);
    ADD_ENUM(SHADER_LOC_COLOR_DIFFUSE);
    ADD_ENUM(SHADER_LOC_COLOR_SPECULAR);
    ADD_ENUM(SHADER_LOC_COLOR_AMBIENT);
    ADD_ENUM(SHADER_LOC_MAP_ALBEDO);
    ADD_ENUM(SHADER_LOC_MAP_METALNESS);
    ADD_ENUM(SHADER_LOC_MAP_NORMAL);
    ADD_ENUM(SHADER_LOC_MAP_ROUGHNESS);
    ADD_ENUM(SHADER_LOC_MAP_OCCLUSION);
    ADD_ENUM(SHADER_LOC_MAP_EMISSION);
    ADD_ENUM(SHADER_LOC_MAP_HEIGHT);
    ADD_ENUM(SHADER_LOC_MAP_CUBEMAP);
    ADD_ENUM(SHADER_LOC_MAP_IRRADIANCE);
    ADD_ENUM(SHADER_LOC_MAP_PREFILTER);
    ADD_ENUM(SHADER_LOC_MAP_BRDF);
    ADD_ENUM(SHADER_LOC_VERTEX_BONEIDS);
    ADD_ENUM(SHADER_LOC_VERTEX_BONEWEIGHTS);
    ADD_ENUM(SHADER_LOC_BONE_MATRICES);
    ADD_ENUM(SHADER_UNIFORM_FLOAT);
    ADD_ENUM(SHADER_UNIFORM_VEC2);
    ADD_ENUM(SHADER_UNIFORM_VEC3);
    ADD_ENUM(SHADER_UNIFORM_VEC4);
    ADD_ENUM(SHADER_UNIFORM_INT);
    ADD_ENUM(SHADER_UNIFORM_IVEC2);
    ADD_ENUM(SHADER_UNIFORM_IVEC3);
    ADD_ENUM(SHADER_UNIFORM_IVEC4);
    ADD_ENUM(SHADER_UNIFORM_SAMPLER2D);
    ADD_ENUM(SHADER_ATTRIB_FLOAT);
    ADD_ENUM(SHADER_ATTRIB_VEC2);
    ADD_ENUM(SHADER_ATTRIB_VEC3);
    ADD_ENUM(SHADER_ATTRIB_VEC4);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_GRAYSCALE);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R5G6B5);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R8G8B8);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R5G5B5A1);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R4G4B4A4);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32G32B32);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R32G32B32A32);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16G16B16);
    ADD_ENUM(PIXELFORMAT_UNCOMPRESSED_R16G16B16A16);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT1_RGB);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT1_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT3_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_DXT5_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC1_RGB);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC2_RGB);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_PVRT_RGB);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_PVRT_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA);
    ADD_ENUM(PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA);
    ADD_ENUM(TEXTURE_FILTER_POINT);
    ADD_ENUM(TEXTURE_FILTER_BILINEAR);
    ADD_ENUM(TEXTURE_FILTER_TRILINEAR);
    ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_4X);
    ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_8X);
    ADD_ENUM(TEXTURE_FILTER_ANISOTROPIC_16X);
    ADD_ENUM(TEXTURE_WRAP_REPEAT);
    ADD_ENUM(TEXTURE_WRAP_CLAMP);
    ADD_ENUM(TEXTURE_WRAP_MIRROR_REPEAT);
    ADD_ENUM(TEXTURE_WRAP_MIRROR_CLAMP);
    ADD_ENUM(CUBEMAP_LAYOUT_AUTO_DETECT);
    ADD_ENUM(CUBEMAP_LAYOUT_LINE_VERTICAL);
    ADD_ENUM(CUBEMAP_LAYOUT_LINE_HORIZONTAL);
    ADD_ENUM(CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR);
    ADD_ENUM(CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE);
    ADD_ENUM(FONT_DEFAULT);
    ADD_ENUM(FONT_BITMAP);
    ADD_ENUM(FONT_SDF);
    ADD_ENUM(BLEND_ALPHA);
    ADD_ENUM(BLEND_ADDITIVE);
    ADD_ENUM(BLEND_MULTIPLIED);
    ADD_ENUM(BLEND_ADD_COLORS);
    ADD_ENUM(BLEND_SUBTRACT_COLORS);
    ADD_ENUM(BLEND_ALPHA_PREMULTIPLY);
    ADD_ENUM(BLEND_CUSTOM);
    ADD_ENUM(BLEND_CUSTOM_SEPARATE);
    ADD_ENUM(GESTURE_NONE);
    ADD_ENUM(GESTURE_TAP);
    ADD_ENUM(GESTURE_DOUBLETAP);
    ADD_ENUM(GESTURE_HOLD);
    ADD_ENUM(GESTURE_DRAG);
    ADD_ENUM(GESTURE_SWIPE_RIGHT);
    ADD_ENUM(GESTURE_SWIPE_LEFT);
    ADD_ENUM(GESTURE_SWIPE_UP);
    ADD_ENUM(GESTURE_SWIPE_DOWN);
    ADD_ENUM(GESTURE_PINCH_IN);
    ADD_ENUM(GESTURE_PINCH_OUT);
    ADD_ENUM(CAMERA_CUSTOM);
    ADD_ENUM(CAMERA_FREE);
    ADD_ENUM(CAMERA_ORBITAL);
    ADD_ENUM(CAMERA_FIRST_PERSON);
    ADD_ENUM(CAMERA_THIRD_PERSON);
    ADD_ENUM(CAMERA_PERSPECTIVE);
    ADD_ENUM(CAMERA_ORTHOGRAPHIC);
    ADD_ENUM(NPATCH_NINE_PATCH);
    ADD_ENUM(NPATCH_THREE_PATCH_VERTICAL);
    ADD_ENUM(NPATCH_THREE_PATCH_HORIZONTAL);
}