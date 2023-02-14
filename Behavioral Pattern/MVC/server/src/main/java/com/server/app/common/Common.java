package com.server.app.common;

import com.server.app.enums.ActiveType;
import org.microdeaf.hbm.model.BaseEntity;

import java.util.Date;

public class Common {

    static public <T extends BaseEntity> void setUserAndDate(T entity) {
        entity.setCreateDate(new Date());
        entity.setCreateBy("admin");
        entity.setIsEnabled(ActiveType.ENABLED.getValue());
    }

    static public <T extends BaseEntity> void updateUserAndDate(T entity) {
        entity.setUpdateDate(new Date());
        entity.setUpdateBy("admin");
        entity.setIsEnabled(ActiveType.ENABLED.getValue());
    }

    static public <T extends BaseEntity> void setUserAndDate(T entity, String username) {
        entity.setCreateDate(new Date());
        entity.setCreateBy(username);
        entity.setIsEnabled(ActiveType.ENABLED.getValue());
    }
}
