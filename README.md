## TWRP device tree for Galaxy S4 (Qualcomm SD600)

Add to `.repo/local_manifests/jflte.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
	<project path="device/samsung/jflte" name="android_device_samsung_jflte" remote="TeamWin" revision="android-6.0" />
</manifest>
```

Then run `repo sync` to check it out.

To build:

```sh
. build/envsetup.sh
lunch omni_jflte-eng
make -j5 recoveryimage
```

Kernel sources are available at: https://github.com/jcadduono/twrp_kernel_samsung_jflte/tree/twrp-6.0

