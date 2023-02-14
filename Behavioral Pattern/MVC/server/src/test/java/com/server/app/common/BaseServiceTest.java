package com.server.app.common;

import com.server.app.enums.ActiveType;
import org.microdeaf.hbm.model.BaseEntity;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Date;

@SpringBootTest
public abstract class BaseServiceTest extends CommonTest {

    protected <T extends BaseEntity> void setUserAndDate(T entity) {
        entity.setCreateDate(new Date());
        entity.setCreateBy("admin");
        entity.setIsEnabled(ActiveType.ENABLED.getValue());
    }

    protected <T extends BaseEntity> void updateUserAndDate(T entity) {
        entity.setUpdateDate(new Date());
        entity.setUpdateBy("admin");
        entity.setIsEnabled(ActiveType.ENABLED.getValue());
    }

}
