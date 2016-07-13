# Release name
PRODUCT_RELEASE_NAME := jflte

$(call inherit-product, build/target/product/embedded.mk)

# Inherit from our custom product configuration
$(call inherit-product, vendor/omni/config/common.mk)

# Loki bootloader exploit
PRODUCT_PACKAGES += \
	loki_tool \
	loki.sh \
	loki_bootloaders \
	recovery-transform.sh

PRODUCT_COPY_FILES += \
	device/samsung/jflte/releasetools/loki.sh:install/bin/loki.sh

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := jflte
PRODUCT_NAME := omni_jflte
PRODUCT_BRAND := samsung
PRODUCT_MANUFACTURER := samsung
