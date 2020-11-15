from conans import ConanFile, Meson


class Main(ConanFile):
    generators = "pkg_config"
    settings = "os", "compiler", "build_type"
    requires = "catch2/3.0.0@catchorg/stable"

    def build(self):
        meson = Meson(self)
        meson.configure()
        meson.build()
