#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // for using std types if needed
#include <pybind11/operators.h> // for operator overloading if needed
#include <rivo/particle.h>
#include <rivo/core.h>

namespace py = pybind11;
using namespace rivo;

PYBIND11_MODULE(rivopy, m) {
    py::class_<Vector3>(m, "Vector3")
        .def(py::init<>())
        .def(py::init<real, real, real>())
        .def_readwrite("x", &Vector3::x)
        .def_readwrite("y", &Vector3::y)
        .def_readwrite("z", &Vector3::z)
        .def("clear", &Vector3::clear)
        .def("addScaledVector", &Vector3::addScaledVector)
        .def("__repr__", [](const Vector3 &v) {
            return "<Vector3 (" + std::to_string(v.x) + ", " +
                   std::to_string(v.y) + ", " +
                   std::to_string(v.z) + ")>";
        });

    py::class_<Particle>(m, "Particle")
        .def(py::init<>())
        .def("setMass", &Particle::setMass)
        .def("getMass", &Particle::getMass)
        .def("setInverseMass", &Particle::setInverseMass)
        .def("getInverseMass", &Particle::getInverseMass)
        .def("hasFiniteMass", &Particle::hasFiniteMass)
        .def("setDamping", &Particle::setDamping)
        .def("getDamping", &Particle::getDamping)
        .def("setPosition", py::overload_cast<const Vector3&>(&Particle::setPosition))
        .def("getPosition", py::overload_cast<>(&Particle::getPosition, py::const_))
        .def("setVelocity", py::overload_cast<const Vector3&>(&Particle::setVelocity))
        .def("getVelocity", py::overload_cast<>(&Particle::getVelocity, py::const_))
        .def("setAcceleration", py::overload_cast<const Vector3&>(&Particle::setAcceleration))
        .def("getAcceleration", py::overload_cast<>(&Particle::getAcceleration, py::const_))
        .def("addForce", &Particle::addForce)
        .def("clearAccumulator", &Particle::clearAccumulator)
        .def("integrate", &Particle::integrate);
}
