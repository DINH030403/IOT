#ifndef INC_DEFINE_STATUS_ZIGBEE_HPP_
#define INC_DEFINE_STATUS_ZIGBEE_HPP_

namespace ZigbeeNamespace {

    enum ZCLStatusT {
        SUCCESS_ZCL = 0,
        FAILURE_ZCL = 1,
        NOT_AUTHORIZED_ZCL = 126,
        RESERVED_FIELD_NOT_ZERO = 127,
        MALFORMED_COMMAND = 128,
        UNSUP_CLUSTER_COMMAND = 129,
        UNSUP_GENERAL_COMMAND = 130,
        UNSUP_MANUF_CLUSTER_COMMAND = 131,
        UNSUP_MANUF_GENERAL_COMMAND = 132,
        INVALID_FIELD = 133,
        UNSUPPORTED_ATTRIBUTE = 134,
        INVALID_VALUE = 135,
        READ_ONLY = 136,
        INSUFFICIENT_SPACE_ZCL = 137,
        DUPLICATE_EXISTS = 138,
        NOT_FOUND = 139,
        UNREPORTABLE_ATTRIBUTE = 140,
        INVALID_DATA_TYPE = 141,
        INVALID_SELECTOR = 142,
        WRITE_ONLY = 143,
        INCONSISTENT_STARTUP_STATE = 144,
        DEFINED_OUT_OF_BAND = 145,
        INCONSISTENT = 146,
        ACTION_DENIED = 147,
        TIMEOUT_ZCL = 148,
        ABORT = 149,
        INVALID_IMAGE = 150,
        WAIT_FOR_DATA = 151,
        NO_IMAGE_AVAILABLE = 152,
        REQUIRE_MORE_IMAGE = 153,
        NOTIFICATION_PENDING = 154,
        HARDWARE_FAILURE = 192,
        SOFTWARE_FAILURE = 193,
        CALIBRATION_ERROR = 194,
        UNSUPPORTED_CLUSTER = 195,
    };

};

#endif /* INC_DEFINE_STATUS_ZIGBEE_HPP_ */
